/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:50:46 by luguimar          #+#    #+#             */
/*   Updated: 2023/06/11 23:19:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_current_stash(int fd, char *stash)
{
	char	*temp;
	int	i;
	ssize_t	bytes;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	i = 0;
	bytes = read(fd, temp, BUFFER_SIZE);
	if (bytes == -1)
	{
		free(temp);
		return (NULL);
	}
	temp[bytes] = '\0';
	stash = 
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_current_stash(fd, buffer);
	if (!stash)
		return (NULL);
	line = get_line(&stash);
	if (!stash[0])
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
