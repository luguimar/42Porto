/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:38:47 by luguimar          #+#    #+#             */
/*   Updated: 2023/07/17 03:09:17 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_stash(char *stash)
{
	int	end;
	int	stash_len;
	int	i;

	end = ft_strchrnum(stash, '\n');
	if (end == -1)
	{
		free(stash);
		return (NULL);
	}
	stash_len = ft_strchrnum(stash, '\0');
	i = 0;
	while (i < stash_len - end)
	{
		stash[i] = stash[end + 1 + i];
		i++;
	}
	stash[i] = '\0';
	return (stash);
}

static char	*get_line(char *stash)
{
	char	*line;
	int		end;
	int		i;

	if (ft_strchrnum(stash, '\n') == -1)
		end = ft_strchrnum(stash, '\0');
	else
		end = ft_strchrnum(stash, '\n') + 1;
	line = malloc(sizeof(char) * end + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < end)
	{
		line[i] = stash[i];
		i++;
	}
	line[end] = '\0';
	if (ft_strchrnum(line, '\0') == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static char	*get_stash(int fd, char *stash)
{
	char	*temp;
	int		bytes;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (temp == NULL)
		return (NULL);
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
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

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
	stash = clean_stash(stash);
	return (line);
}
