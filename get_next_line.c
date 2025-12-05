/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:48:48 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/03 09:50:33 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/* int ft_find_end_of_the_line(char *temp, int i, int *ptr_check_end)
{
	int	a;

	a = 0;
	while (temp[i + a] !='\0' && temp[i + a] !='\n')
		a++;
	if (temp[i + a] !='\n')
		return (0);
	else if(temp[i + a] =='\n')
		return (a);
	else
	{
		*ptr_check_end = 1;
		return (a);
	}
} */


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

	lenstash = 0;
	if (stash != NULL)
	{
		while (stash[lenstash])
				lenstash++;
	}
	place_n = ft_find_end_of_the_line(stash, 0);
	if (from == 'l')
	{
		line = ft_substr(stash, 0, place_n + 1);
		return (line);
	}
	else
	{
		stash = ft_substr(stash, place_n + 1, (lenstash - place_n));
		return (stash);
	}
}

char *ft_remplir_stash (char *buffer, char *stash)
{
	char	*tempstash;
	int	lenstash;

	lenstash = 0;
	if (stash != NULL)
	{
		while (stash[lenstash])
				lenstash++;
	}
	tempstash = ft_substr(stash, 0, lenstash);
	free(stash);
	stash = ft_strjoin(tempstash, buffer);
	free(tempstash);
	return (stash);
}

char *get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	*stash = NULL;
	int	check_end;
	char	*line;
	size_t endfile;

	check_end = 0;
	endfile = read (fd, buffer, BUFFER_SIZE);
	while (check_end == 0 && (endfile <= BUFFER_SIZE || fr_strlen(stash) <= BUFFER_SIZE))
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
	if (endfile == 0)
		return (NULL);
	else if  (endfile < BUFFER_SIZE && endfile != 0)
	{
		// stash = ft_remplir_stash(buffer, stash);
		line = ft_line_and_clean_stash(stash, 'l');
	}
	stash = ft_line_and_clean_stash(stash, 's');
	return (line);
}



#include <fcntl.h>
#include <stdio.h>
int main (void)
{
	int	fd = open("./coucou.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}