/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:48:48 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/06 20:24:02 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"


int ft_find_end_of_the_line(char *stash, int	from)
{
	int	a;

	a = 0;
	while (stash[a] !='\n' && stash[a] !='\0')
		a++;
	if (from == 1)
	{
		if (stash[a] == '\n')
			return (0);
		else
			return (a);
	}
	else
		return (a);
	
}
char	*ft_line_and_clean_stash(char *stash, char from)
{
	int	place_n;
	int	lenstash;
	char	*line;
	char *temp_stash;

	lenstash = 0;
	if (stash != NULL)
		lenstash = ft_strlen(stash);
	place_n = ft_find_end_of_the_line(stash, 0);
	if (from == 'l')
	{
		line = ft_substr(stash, 0, place_n + 1);
		return (line);
	}
	else
	{
		temp_stash = stash;
		stash = ft_substr(temp_stash, place_n + 1, (lenstash - place_n));
		free(temp_stash);
		return (stash);
	}
}

char	*ft_remplir_stash (char *buffer, char *stash)
{
	char	*tempstash;

	tempstash = stash;
	stash = ft_strjoin(tempstash, buffer);
	free(tempstash);
	return (stash);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*stash = NULL;
	static int	Buffer_too_big = 0;
	int	check_end;
	char	*line;
	size_t endfile;

	check_end = 0;
	endfile = read (fd, buffer, BUFFER_SIZE);
	if (stash == NULL && endfile < BUFFER_SIZE)
		Buffer_too_big = 1;
	while (check_end == 0 && endfile != 0 &&(endfile == BUFFER_SIZE || Buffer_too_big == 1))
	{
		stash = ft_remplir_stash(buffer, stash);
		if(!ft_find_end_of_the_line(stash, 1))
		{
			line = ft_line_and_clean_stash(stash, 'l');
			check_end = 1;
		}
		else
			endfile = read (fd, buffer, BUFFER_SIZE);
	}
	if  (endfile < BUFFER_SIZE && ft_strlen(stash) > 0 && check_end == 0)
		line = ft_line_and_clean_stash(stash, 'l');
	else if (endfile == 0)
		return (NULL);
	stash = ft_line_and_clean_stash(stash, 's');
	return (line);
}

/* #include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int	fd = open("./coucou.txt", O_RDONLY);
	
	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
} */