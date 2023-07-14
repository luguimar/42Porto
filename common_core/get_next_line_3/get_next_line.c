/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:38:47 by luguimar          #+#    #+#             */
/*   Updated: 2023/07/14 22:51:52 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*restash(char *stash)
{
	char 	*temp;
	int	start;
	int	stashlen;
	int	i;

	i = -1;
	start = ft_strchrnum(stash, '\n');
	stashlen = ft_strchrnum(stash, '\0') - start - 1;
	if (start == -1)
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substr(stash, start + 1, stashlen);
	while (temp[++i] != '\0')
		stash[i] = temp[i];
	free(temp);
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int	end;
	int	i;

	i = -1;
	end = ft_strchrnum(stash, '\n');
	if (end == -1)
	{
		end = ft_strchrnum(stash, '\0');
		line = malloc(sizeof(char) * (end + 1));
		if (line == NULL)
		{
			free(stash);
			return (NULL);
		}
		line[end] = '\0';
	}
	else
	{
		line = malloc(sizeof(char) * (end + 2));
		if (line == NULL)
		{
			free(stash);
			return (NULL);
		}
		line[end] = '\n';
		line[end + 1] = '\0';
	}
	while (++i < end)
		line[i] = stash[i];
	return (line);
}

static char	*get_stash(int fd, char *stash)
{
	char	*temp;
	int	bytes;

	while (stash[0] != '\0')
		stash = restash(stash);
	while (ft_strchrnum(stash, '\n') != -1)
		stash = restash(stash);
	if (stash == NULL)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && ft_strchrnum(stash, '\n') == -1)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[bytes] = '\0';
		stash = ft_strjoin(stash, temp);
	}
	free(temp);
	if (ft_strchrnum(stash, '\0') != 0)
		return (stash);
	free(stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		if (stash == NULL)
			return (NULL);
		stash[0] = '\0';
	}
	stash = get_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = get_line(stash);
	return (line);
}
