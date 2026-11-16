/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:38 by romasant          #+#    #+#             */
/*   Updated: 2026/11/16 23:43:47 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	const char	*src_origin;

	size_t (counter_dst) = 0;
	size_t (counter_size) = 0;
	src_origin = src;
	while (src[counter_size])
		counter_size++;
	if (dstsize == 0)
		return (counter_size);
	while (*src && counter_dst < dstsize - 1)
	{
		*dst = *src;
		counter_dst++;
		dst++;
		src++;
	}
	*dst = '\0';
	counter_size = 0;
	while (src_origin[counter_size] != '\0')
		counter_size++;
	return (counter_size);
}

ssize_t	ft_read_and_extra(int fd, char *buffer)
{
	ssize_t	size_bytes;

	int (i) = 0;
	size_bytes = 0;
	while (i <= (BUFFER_SIZE + 1))
	{
		size_bytes = read(fd, &buffer[i], i);
		if (size_bytes == -1)
			return (-1);
		if (buffer[i] == '\n')
			return (size_bytes);
		i++;
	}
	return (size_bytes);
}
