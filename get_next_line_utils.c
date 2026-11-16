/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:38 by romasant          #+#    #+#             */
/*   Updated: 2026/11/16 23:02:52 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
