/* ************************************************************************** */
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

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
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
		len	= ft_strlen(str);
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
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
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
