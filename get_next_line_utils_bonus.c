/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:05:40 by shifterpro        #+#    #+#             */
/*   Updated: 2023/05/04 11:25:05 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (free(s1), NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (free(s1), NULL);
	ft_memcpy(str, s1, size1);
	ft_memcpy(str + size1, s2, size2);
	str[size1 + size2] = 0;
	free(s1);
	return (str);
}

int	check_byteread_and_linebreak(char *str, int byte_read)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	if (byte_read == 0)
		return (1);
	while (str[i] != 0)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
