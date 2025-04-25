/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:11:27 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/25 16:14:29 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n;

	line = NULL;
	if (buf[0])
		line = add_line(line, buf);
	while (!ft_strchr(line, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
		{
			shift_buf(buf);
			free(line);
			return (NULL);
		}
		if (n == 0)
			break ;
		if (n < BUFFER_SIZE)
			buf[n] = 0;
		line = add_line(line, buf);
	}
	shift_buf(buf);
	return (line);
}
/*
#include <stdio.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*line;

	(void)ac;
	int	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
*/
