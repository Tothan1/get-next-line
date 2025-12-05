/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:48:56 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/03 09:47:36 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 300
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(char *str, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_secondtab(int i, char *newstr, char *str2);
char *ft_remplir_stash (char *buffer, char *stash);
char *get_next_line(int fd);







#endif /* GET_NEXT_LINE_H */