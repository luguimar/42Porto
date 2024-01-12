/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:24:46 by shrodrig          #+#    #+#             */
/*   Updated: 2024/01/03 15:25:38 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(int fd, char *str)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (!ft_strchr(str, '\n') && bytesread != 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free (buffer);
			free (str);
			return (NULL);
		}
		buffer[bytesread] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10000];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 10000)
		return (NULL);
	str[fd] = ft_read_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_get_newstr(str[fd]);
	return (line);
}
/*
int	main (void)
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;
	int		rdlines;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	rdlines = 1;
	line = "a";
	while(line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%d -> %s",rdlines, line);
		line = get_next_line(fd2);
		printf("%d -> %s",rdlines, line);
		line = get_next_line(fd3);
		printf("%d -> %s",rdlines++, line);
	}
	free (line);
	close(fd);
	return (0);
}*/