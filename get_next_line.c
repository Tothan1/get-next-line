/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:48:48 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/11/30 11:59:53 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
int ft_find_end_of_the_file(char *temp)
{
	int	a;

	a = 0;
	while (temp[a] !='\0')
		a++;
	if (temp[a] !='\0')
		return (0);
	else
		return (a);
}

char *get_next_line(int fd)
{
	static char	tab[BUFFER_SIZE];
	int	i;
	
	i= 0;
	// int buffer = BUFFER_SIZE;
	// static int	check_end;
	// static int	*ptr_check_end;
	
	// check_end = 0;
	// ptr_check_end = &check_end;
	char *str;
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);

	read (fd, tab, BUFFER_SIZE);
	/* if( check_end == 0 && !ft_find_end_of_the_line(tab, i, ptr_check_end))
	{
		str = malloc(sizeof(char) * (ft_find_end_of_the_line(tab, i, ptr_check_end)) + 1);
		i +=ft_find_end_of_the_line(tab, i, ptr_check_end); 
		printf("détect");
	}
	else
	{
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		i +=BUFFER_SIZE;
	}
	if (str == NULL)
		return (NULL); */
	if (ft_find_end_of_the_file(tab))
	{
		while (i<BUFFER_SIZE)
		{
			str[i] = tab[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
		
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
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}