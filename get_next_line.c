/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:25:59 by romasant          #+#    #+#             */
/*   Updated: 2026/11/18 18:37:14 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*rest;
	static char	*stock;

	size_t (size) = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stock = ft_read_stock(fd, stock, buffer);
	free(buffer);
	if (!stock)
		return (NULL);
	rest = ft_strchr(stock, '\n');
	size = ft_strlen(stock);
	if (rest)
		size = rest - stock + 1;
	rest = ft_substr(stock, size, ft_strlen(stock) - size);
	if (!rest)
		return (NULL);
	buffer = ft_substr(stock, 0, size);
	free(stock);
	stock = rest;
	return (buffer);
}
