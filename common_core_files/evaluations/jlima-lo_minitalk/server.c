/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlima-lo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:44:40 by jlima-lo          #+#    #+#             */
/*   Updated: 2023/07/05 12:44:42 by jlima-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	srv_handle(int sinal)
{
	static unsigned char	c;
	static int				bits;

	if (sinal == SIGUSR1)
		c = c | (1 << bits);
	bits += 1;
	if (bits == 8)
	{
		ft_printf("%c", c);
		bits = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Seu Burro!\nCorre apenas <./server>");
		return (1);
	}
	else
	{
		pid = getpid();
		ft_printf("PID : %i\n", pid);
		ft_printf("Waiting...\n");
		while (1)
		{
			signal(SIGUSR1, srv_handle);
			signal(SIGUSR2, srv_handle);
		}
	}
	return (0);
}
