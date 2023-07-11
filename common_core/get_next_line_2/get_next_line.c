/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 20:38:47 by luguimar          #+#    #+#             */
/*   Updated: 2023/07/11 23:52:16 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *stash)
{
	char	*line;
	int		end;
	int		i;

	i = 0;
	if (ft_strchrnum(stash, '\n') == -1)
		end = ft_strchrnum(stash, '\0');
	else
		end = ft_strchrnum(stash, '\n');
	line = malloc(sizeof(char) * end + 1);
	if (!line)
		return (NULL);
	while (i < end)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*get_current_stash(int fd, char *stash)
{
	char	*temp;
	int		bytes;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
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
	if (ft_strchrnum(stash, '\0') > 0)
		return (stash);
	free(stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;
	int	nwstashbg;
	char	*tempstash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	stash = get_current_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = get_line(stash);
	if (ft_strchrnum(stash, '\n') == -1)
		nwstashbg = ft_strchrnum(stash, '\0');
	else
		nwstashbg = ft_strchrnum(stash, '\n');
	tempstash = stash;
	stash = ft_substr(tempstash, nwstashbg, ft_strchrnum(tempstash, '\0') - nwstashbg);
	free(tempstash);
	return (line);
}
