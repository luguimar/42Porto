/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <arosa-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:10:55 by arosa-de          #+#    #+#             */
/*   Updated: 2024/04/03 17:18:04 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Handles SIGUSR1 and SIGUSR2 signals by
// shifting and ORing the bits of a character,
// and sends a confirmation signal back to the sender

// Counter for the number of bits received

// Character being built from the received bits

// Unused parameter

// Shift the character left and set the least
// significant bit to 1 if the signal is SIGUSR1;
// otherwise, shift the character left and set the
// least significant bit to 0

// If 8 bits have been received, print the character and
// reset the counter and character, and send a SIGUSR1
// signal back to the sender as a confirmation

// si_pid is the process ID of the sender

// Send a SIGUSR2 signal back to the sender as a confirmation

// si_pid is the process ID of the sender

void	message_handler(int sig, siginfo_t *info, void *content)
{
	static int				bit = 0;
	static unsigned char	c = 0;

	(void)content;
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

// Print the process ID

// Set up the signal handler for SIGUSR1 and
// SIGUSR2 and wait for signals indefinitely

int	main(void)
{
	struct sigaction	action;
	int					pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	action.sa_sigaction = &message_handler;
	action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
	{
		pause();
	}
}
