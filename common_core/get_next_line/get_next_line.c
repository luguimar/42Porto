/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:50:46 by luguimar          #+#    #+#             */
/*   Updated: 2023/06/12 02:03:42 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **stash)
{
	char	*line;
	char	*new_stash;
	size_t	til_newl;
	size_t	len;

	line = NULL;
	new_stash = NULL;
	til_newl = 0;
	len = ft_strlen(*stash);
	while ((*stash)[til_newl] != '\n' && til_newl < len)
		til_newl++;
	if ((*stash)[til_newl] == '\n')
		til_newl++;
	ft_memmove(line, *stash, til_newl);
	if (!line)
		return (NULL);
	ft_memmove(new_stash, *stash + til_newl, len - til_newl + 1);
	if (!new_stash)
	{
		free(line);
		return (NULL);
	}
	free(*stash);
	*stash = new_stash;
	return (line);
}

static char	*get_current_stash(int fd, char *stash)
{
	char	*temp;
	ssize_t	bytes;

	bytes = 1;
	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	temp[BUFFER_SIZE] = '\0';
	while (bytes > 0 && !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	if (ft_strlen(stash) > 0)
		return (stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_current_stash(fd, stash);
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
