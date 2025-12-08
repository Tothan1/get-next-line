/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:49:06 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/08 17:51:14 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_secondtab(int i, char *newstr, char *s2, int limits)
{
	int	b;

	b = 0;
	while (s2 != NULL && s2[b] != '\0' && b < limits)
	{
		newstr[i] = s2[b];
		i++;
		b++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2, int limits)
{
	int		i;
	int		len;
	char	*newstr;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + limits;
	newstr = (char *)malloc(sizeof(char) * len + 1);
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	return (ft_secondtab(i, newstr, s2, limits));
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	alloc_len;
	char	*newstr;

	if (!str)
		return (NULL);
	if (len > ft_strlen(str) - start)
		alloc_len = ft_strlen(str) - start;
	else
		alloc_len = len;
	newstr = (char *)malloc(sizeof(char) * (alloc_len + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	while (i < alloc_len && i < (ft_strlen(str)))
	{
		newstr[i] = str[i + start];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
