/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romasant <romasant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 21:14:06 by romasant          #+#    #+#             */
/*   Updated: 2026/11/15 21:27:31 by romasant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	fd = open("/mnt/c/Users/croco/Desktop/42/M1_42/get_next_line/test.txt", O_RDONLY);
	if (!fd)
		return (-1);
	printf("%s\n", get_next_line(fd));
	return (0);
}
