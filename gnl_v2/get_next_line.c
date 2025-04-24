/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:11:27 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/24 16:13:59 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		n;

	if (!buf[0])
		n = read(fd, buf, BUFFER_SIZE);
	while (!ft_strchr(line, '\n'))
	{
		line = put_line(line, buf);
		
	}
}

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

