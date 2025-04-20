/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:35:34 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/17 16:01:04 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read(fd, buff, BUFFER_SIZE) > 0 || ft_strchr(stash, '\n'))
	{
		if (stash && ft_strchr(stash, '\n'))
		{
			stash = ft_strjoin(stash, buff);
			line = ft_substr(stash, 0, strlen_x(stash, '\n'));
			stash = ft_substr(stash, strlen_x(stash, '\n') + 1, strlen_x(stash, 0));
			return (line);
		}
		else if (stash && !ft_strchr(stash, '\n'))
			stash = ft_strjoin(stash, buff); 
		else if (!stash)
			stash = ft_strdup(buff);
		else
			return (NULL);
	}
	return (NULL);
}
/*
const char	*add_to_stash(static char *stash, char *buff)
{
	char	*temp;
	size_t	stash_len;

	if (!stash)
		return (ft_strdup(buff));
	stash_len = ft_strlen(stash);
	temp = ft_strdup(stash);
	free(stash);
	stash = malloc(sizeof(char) * (stash_len + BUFFER_SIZE + 1));
	stash = ft_strjoin(stash, buff);
	return (stash);
}
*/
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	char	*line;

	(void)ac;
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("----- line 1 ^ -----\n");
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("----- line 2 ^ -----\n");
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("----- line 3 ^ -----\n");
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("----- line 4 ^ -----\n");
	line = get_next_line(fd);
	printf("%s\n", line);
	printf("----- line ? ^ -----\n");
}
