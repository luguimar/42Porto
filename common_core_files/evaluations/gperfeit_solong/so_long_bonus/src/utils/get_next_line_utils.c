/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:17:49 by gperfeit          #+#    #+#             */
/*   Updated: 2023/04/25 19:13:19 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stddef.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	memlen;
	void	*allocmem;

	if (size > 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	memlen = nmemb * size;
	allocmem = malloc(memlen);
	return (allocmem);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

ssize_t	parse_buff(char *buff, char *end, char **line, size_t *linelen)
{
	char	*newline;
	size_t	i;

	i = 0;
	while ((buff + i) < end)
	{
		if (buff[i++] == '\n')
			break ;
	}
	newline = ft_calloc(*linelen + i + 1, sizeof(char));
	if (!newline)
		return (-1);
	if (line)
	{
		ft_memcpy(newline, *line, *linelen * sizeof(char));
		free(*line);
	}
	ft_memcpy(newline + *linelen, buff, i * sizeof(char));
	*linelen += i;
	newline[*linelen] = '\0';
	*line = newline;
	return (i);
}

int	is_prevfd(int newfd)
{
	static int	prevfd = -1;
	int			res;

	res = newfd == prevfd;
	prevfd = newfd;
	return (res);
}
