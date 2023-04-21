/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:27:11 by shifterpro        #+#    #+#             */
/*   Updated: 2023/04/21 13:27:14 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size1;
	size_t	size2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	i = -1;
	j = -1;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc(sizeof(*s1) * (size1 + size2 + 1));
	if (!str)
		return (0);
	while (++i < size1)
		str[i] = s1[i];
	while (++j < size2)
		str[i + j] = s2[j];
	str[i + j] = 0;
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(str + i) = 0;
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zero;

	zero = (void *)malloc(nmemb * size);
	if (!zero)
		return (0);
	ft_bzero(zero, size * nmemb);
	return (zero);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}
