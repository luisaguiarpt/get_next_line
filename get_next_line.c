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

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buff;
	size_t		nbytes;

	c = 0;
	stash = NULL;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	nbytes = read(fd, buff, BUFFER_SIZE);
	stash = add_to_stash(stash, buff);
}

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

#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	char	*line;
	while (line = get_next_line(fd))
	{
		printf("%s", line);
	}

}
