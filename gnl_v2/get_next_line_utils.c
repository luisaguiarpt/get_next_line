/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:01:13 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/24 16:13:56 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*put_line(char *line, char *buf)
{
	char	*new;
	ssize_t	i;

	i = 0;
	while (buf && buf[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (ft_strlen(line) + i + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (line && line[++i])
		new[i] == line[i];
	
	shift_buf(buf, n);

}

void	shift_buf(char *buf, ssize_t n)
{
	size_t	i;
	size_t	dest;
	size_t	src;

	dest = 0;
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	src = i + (buf[i] == '\n');
	while (buf[i])
		i++;
	while (src <= i && n--)
		buf[dest++] = buf[src++];
	buf[dest] = 0;
}

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (*s == uc)
		return ((char *)s);
	return (NULL);
}
