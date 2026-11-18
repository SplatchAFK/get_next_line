/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 20:26:38 by romasant          #+#    #+#             */
/*   Updated: 2026/11/18 18:36:19 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter_size;

	counter_size = 0;
	while (s[counter_size] != '\0')
		counter_size++;
	return (counter_size);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s2)
		return (NULL);
	len = ft_strlen(s2);
	if (s1)
		len += ft_strlen(s1);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1 && *s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	if (start > slen - start)
		len = slen - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_read_stock(int fd, char *stock, char *buffer)
{
	char	*tmp;

	ssize_t (nb_bytes) = 1;
	while ((!stock || !ft_strchr(stock, '\n')) && nb_bytes > 0)
	{
		nb_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(stock);
			return (NULL);
		}
		buffer[nb_bytes] = '\0';
		tmp = stock;
		stock = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!stock)
			return (NULL);
	}
	if (!*stock)
	{
		free(stock);
		return (NULL);
	}
	return (stock);
}
