/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourbon <mcourbon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:05:43 by shifterpro        #+#    #+#             */
/*   Updated: 2023/05/02 11:59:07 by mcourbon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_next_buffer(char *buffer);
char	*ft_get_line(char *buffer);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, void *src, size_t size);
char	*ft_free_strjoin(char *s1, char *s2);
int		check_byteread_and_linebreak(char *str, int byte_read);

#endif