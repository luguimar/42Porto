/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:23:52 by luguimar          #+#    #+#             */
/*   Updated: 2023/02/22 20:36:09 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void	ft_putchar(char c);
int	theight(char *str);
int	twidth(char *str);
char	*threechars(char *map, char *three);
char	**ft_matriz(int width, int height);
void	fillmatrix(char *map, char **matriz, int height);
void	writearray(char *map, char **matrix);

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
	char	**matrix;
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
	threechars(map, symbols);
	matrix = ft_matriz(twidth(map), theight(map));
	fillmatrix(map, matrix, theight(map));
	writearray(map, matrix);
	return (0);
}
