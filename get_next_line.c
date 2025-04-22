/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:35:34 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/22 23:19:46 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*saf;
	char		*buf;
	ssize_t		nbytes;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	buf[BUFFER_SIZE] = 0;
	while (!ft_strchr(saf, '\n'))
	{
		nbytes = read(fd, buf, BUFFER_SIZE);
		if (nbytes < 1 && (!saf || saf[0] == 0 || nbytes == -1))
		{
			free(saf);
			saf = NULL;
			free(buf);
			return (NULL);
		}
		else if (nbytes < 1)
			break ;
		saf = store_in_saf(saf, buf, nbytes);
	}
	free(buf);
	return (put_line(saf));
}

char	*store_in_saf(char *saf, char *buf, ssize_t nbytes)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen(saf) + nbytes + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (saf && saf[i])
	{
		new[i] = saf[i];
		i++;
	}
	while (nbytes-- > 0)
	{
		new[i] = *buf++;
		i++;
	}
	new[i] = 0;
	if (saf)
		free(saf);
	return (new);
}

char	*put_line(char *saf)
{
	int		i;
	char	*line;

	i = 0;
	while (saf[i])
	{
		if (saf[i] == '\n' || saf[i + 1] == 0)
		{
			line = malloc(sizeof(char) * (i + 2));
			if (!line)
				return (NULL);
			line[i + 1] = 0;
			while (i >= 0)
			{
				line[i] = saf[i];
				i--;
			}
			move_saf(saf);
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*move_saf(char *saf)
{
	size_t	i;
	size_t	dest;
	size_t	src;

	dest = 0;
	i = 0;
	while (saf[i] && saf[i] != '\n')
		i++;
	src = i + (saf[i] == '\n');
	while (saf[i])
		i++;
	while (src < i)
		saf[dest++] = saf[src++];
	saf[dest] = 0;
	return (saf);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	char	*line;

	(void)ac;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		printf("----------- line ^ ------------\n");
		free(line);
	}	
	close(fd);
	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		printf("----------- line ^ ------------\n");
		free(line);
	}	
	printf("%s", line);
	printf("----------- line ^ ------------\n");
	free(line);
}
*/
