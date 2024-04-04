/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-de <arosa-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:11:10 by arosa-de          #+#    #+#             */
/*   Updated: 2024/04/03 17:18:00 by arosa-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// Sends the specified message to the specified
// process using SIGUSR1 and SIGUSR2 signals

// Initialize variables

// Iterate through each character of the message

// Iterate through each bit of the current character

// If the current bit is 1, send SIGUSR1 signal;
// otherwise, send SIGUSR2 signal

// Sleep for 100 microseconds between each signal

void	send_message(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit++;
		usleep(100);
	}
}

// Validate the number of arguments

// Convert the server ID (PID) to an integer and
// send the message using the signal_action function

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*message;

	if (ac != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Correct format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	message = av[2];
	i = 0;
	while (message[i])
	{
		send_message(pid, message[i]);
		i++;
	}
	send_message(pid, message[i]);
}
