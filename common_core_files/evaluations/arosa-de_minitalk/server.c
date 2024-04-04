/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <arosa-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:55 by arosa-de          #+#    #+#             */
/*   Updated: 2024/04/03 17:18:11 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Handles SIGUSR1 and SIGUSR2 signals by shifting
// and ORing the bits of a character

// Counter for the number of bits received

// Character being built from the received bits

// Shift the character left and set the least
// significant bit to 1 if the signal is SIGUSR1;
// otherwise, shift the character left and set the
// least significant bit to 0

// If 8 bits have been received, print the
// character and reset the counter and character

void	message_handler(int sig)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

// Print the process ID

// Set up the signal handlers and wait for signals indefinitely

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_handler = &message_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
}
