/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:42:53 by luguimar          #+#    #+#             */
/*   Updated: 2023/06/11 20:06:57 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	cena(fd)
{
	int		bytes;
	int		i;
	char	*something;
	char	*ch;

	ch = (char *)malloc(1);
	i = 0;
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	something = (char *)malloc(11);
	bytes = read(fd, ch, 1);
	while (bytes > 0 && i < 10)
	{
		something[i] = *ch;
		bytes = read(fd, ch, 1);
		i++;
	}
	something[i] = '\0';
	printf("%s", something);
	free(something);
	free(ch);
	return (0);
}

int	main(void)
{
	int	returned;
	int	fd;

	fd = open("algo.txt", O_RDONLY);
	returned = cena(fd);
	returned = cena(fd);
	close(fd);
	return (retornado);
}
