/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:01:51 by aamaral-          #+#    #+#             */
/*   Updated: 2024/01/09 21:01:56 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philofork_malloc(t_data *data)
{
	free (data->philo);
	free (data->fork_locker);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philos)
		pthread_mutex_destroy(&data->fork_locker[i]);
	free_philofork_malloc(data);
	pthread_mutex_destroy(&data->print_locker);
	pthread_mutex_destroy(&data->eat_locker);
	pthread_mutex_destroy(&data->end_locker);
}

void	end_simulation(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->number_philos)
		pthread_join(data->philo[i].thread, NULL);
	destroy_mutex(data);
}

int	destroy(char *msg, t_data *data, int option)
{
	printf("Error: %s\n", msg);
	if (option == 1)
	{
		free_philofork_malloc(data);
		return (42);
	}
	if (option == 2)
	{
		destroy_mutex(data);
		return (42);
	}
	if (option == 3)
	{
		end_simulation(data);
		return (42);
	}
	return (42);
}
