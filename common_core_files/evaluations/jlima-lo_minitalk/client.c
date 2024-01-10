/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:44:23 by jlima-lo          #+#    #+#             */
/*   Updated: 2023/07/05 12:44:25 by jlima-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send(int pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((c & (1 << bits)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bits++;
		usleep(600);
	}
	bits = 0;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	count;

	count = 0;
	if (argc != 3)
	{
		ft_printf("Seu Burro!\nCorre apenas <./client> + <PID> + <string>\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][count] != '\0')
	{
		send(pid, argv[2][count]);
		count++;
	}
	send(pid, '\n');
	return (0);
}
