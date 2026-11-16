/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:25:59 by romasant          #+#    #+#             */
/*   Updated: 2026/11/16 23:26:48 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];

	ssize_t	(nb_bytes_read) = 0;
	nb_bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_bytes_read == -1 || nb_bytes_read == 0)
		return (NULL);
	buffer[nb_bytes_read] = '\0';
	str = malloc(sizeof(char) * (nb_bytes_read + 1));
	ft_strlcpy(str, buffer, nb_bytes_read);
	return (str);
}
