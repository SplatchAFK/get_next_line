/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:25:59 by romasant          #+#    #+#             */
/*   Updated: 2026/11/15 21:46:22 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];

	ssize_t	(nb_bytes_read) = 0;
	ssize_t	(nb_bytes_read_final) = 0;
	buffer[BUFFER_SIZE + 1] = '\0';
	nb_bytes_read = ft_read_and_extra(fd, buffer);
	nb_bytes_read_final = BUFFER_SIZE - nb_bytes_read;

	printf("Voici le nombre de bytes lu : %ld\n", nb_bytes_read_final);
	str = malloc(sizeof(char) * ( + 1));
	return (str);
}
