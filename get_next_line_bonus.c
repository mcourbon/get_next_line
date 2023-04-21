/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shifterpro <shifterpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:29:05 by shifterpro        #+#    #+#             */
/*   Updated: 2023/04/21 14:08:49 by shifterpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_strjoin(char *buffer, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(buffer, buf);
	free(buffer);
	return (tmp);
}

char	*ft_get_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*tmp;
	int		byte_read;

	if (!buffer)
		buffer = calloc(1, 1);
	tmp = calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte_read] = 0;
		buffer = ft_free_strjoin(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[65534];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd > 65534)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
	{
		free(buffer[fd]);
		return (NULL);
	}
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_next_buffer(buffer[fd]);
	return (line);
}
