/************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:47:25 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/17 15:55:52 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

size_t	strlen_x(const char *str, char x)
{
	size_t	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len] != x)
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	size_t	len;
	int		i;

	i = 0;
	if (!str)
		len = 0;
	else
		len	= strlen_x(str, '\0');
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (str[i] && len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*new;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	len = strlen_x(s1, '\0') + strlen_x(s2, '\0') + 1;
	new = malloc(sizeof(char) * len);
	if (!new)
		return (NULL);
	ptr = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = 0;
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	
	uc = (unsigned char)c;
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= strlen_x(s, '\0'))
		len = 0;
	if (len > strlen_x(s, '\0') - start)
		len = strlen_x(s, '\0') - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
