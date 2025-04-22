/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldias-da <ldias-da@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:28:58 by ldias-da          #+#    #+#             */
/*   Updated: 2025/04/22 23:15:47 by ldias-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10
# endif

char	*get_next_line(int fd);
char	*store_in_saf(char *saf, char *buf, ssize_t nbytes);
char	*put_line(char *saf);
char	*move_saf(char *saf);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif
