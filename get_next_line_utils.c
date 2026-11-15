/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:38 by romasant          #+#    #+#             */
/*   Updated: 2026/11/15 22:02:05 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_read_and_extra(int fd, char *buffer)
{
	ssize_t	size_bytes;
	int (i) = 0;

	size_bytes = 0;
	while (buffer[i])
	{
		size_bytes = read(fd, &buffer[i], i);
		if (buffer[i] == '\n')
		{
			printf("\nVoici le nombre de bytes que je return : %ld\n", size_bytes);	
			return (size_bytes);
		}
		i++;
	}
	if (size_bytes == -1)
		return (-1);
	return (size_bytes);
}
