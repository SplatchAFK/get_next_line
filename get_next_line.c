/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:25:59 by romasant          #+#    #+#             */
/*   Updated: 2026/11/16 23:01:30 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	char	buffer[BUFFER_SIZE + 1];
	int		i;

	ssize_t	(nb_bytes_read) = 0;
	buffer[BUFFER_SIZE + 1] = '\0';
	i = 0;
	nb_bytes_read = ft_read_and_extra(fd, buffer);

	printf("Voici le nombre de bytes lu : %ld\n", nb_bytes_read);
	str = malloc(sizeof(char) * (nb_bytes_read + 1));
	while (i < nb_bytes_read)
	{
		str[i] = 
		i++;
	}
	str[nb_bytes_read + 1] = '\n';
	return (str);
}
