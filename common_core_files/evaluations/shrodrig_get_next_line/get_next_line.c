/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shrodrig <shrodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:19:51 by shrodrig          #+#    #+#             */
/*   Updated: 2024/01/03 15:25:41 by shrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line (fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_newstr(str);
	return (line);
}
/*
int	main (void)
{
	char	*line;
	int		fd;
	int		rdlines;

	fd = open("test.txt", O_RDONLY);
	rdlines = 0;
	while((line = get_next_line(fd)))
		printf("%d -> %s",++rdlines, line);
	free (line);
	close(fd);
	return (0);
}*/