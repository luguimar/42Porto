/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:52 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/22 16:33:40 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int	theight(char *str);
int	twidth(char *str);
char	*threechars(char *map, char *three);

int	mapsize(char *argv1)
{
	int	length;
	int	fd;
	int	buff;

	length = 0;
	fd = open(argv1, O_RDONLY);
	while (read(fd, &buff, 1))
		length++;
	close(fd);
	return (length);
}

int	main(int argc, char *argv[])
{
	int		fd;
	int		length;
	char	*map;
	char	symbols[3];

	if (argc != 2)
	{
		write(1, "Wrong number of params", 22);
		exit(0);
	}
	length = mapsize(argv[1]);
	map = (char *)malloc(sizeof(char) * length);
	fd = open(argv[1], O_RDONLY);
	read(fd, map, length);
	printf("%d\n", twidth(map));
	printf("%d\n", theight(map));
	threechars(map, symbols);
	printf("%c %c %c", symbols[0], symbols[1], symbols[2]);

	return (0);
}
