/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:01:41 by aamaral-          #+#    #+#             */
/*   Updated: 2024/01/09 21:01:43 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	change_end_flag(t_philo *philo, int must_end)
{
	pthread_mutex_lock(&philo->data->end_locker);
	if (philo->data->end_flag || must_end)
	{
		if (must_end)
			philo->data->end_flag = true;
		pthread_mutex_unlock(&philo->data->end_locker);
		return (true);
	}
	pthread_mutex_unlock(&philo->data->end_locker);
	return (false);
}

void	print_action(t_philo *philo, const char *action)
{
	long long	time;

	pthread_mutex_lock(&philo->data->print_locker);
	if (!change_end_flag(philo, false))
	{
		time = millisec_time() - philo->data->start_time;
		printf("%lld %d %s\n", time, philo->number, action);
	}
	pthread_mutex_unlock(&philo->data->print_locker);
	if (action[0] == 'f')
		printf("All philosophers has eaten at least %d times.\n", \
		philo->data->times_must_eat);
}

void	start_eating(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->fork_locker[philo->left_fork]);
		pthread_mutex_lock(&philo->data->fork_locker[philo->rigth_fork]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->fork_locker[philo->rigth_fork]);
		pthread_mutex_lock(&philo->data->fork_locker[philo->left_fork]);
	}
	print_action(philo, "has taken a fork");
	print_action(philo, "has taken a fork");
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->eat_locker);
	philo->eating_flag = true;
	philo->start_meal = millisec_time();
	pthread_mutex_unlock(&philo->data->eat_locker);
	advance_time(philo, philo->data->time_to_eat);
	pthread_mutex_lock(&philo->data->eat_locker);
	philo->eat_counter++;
	philo->eating_flag = false;
	philo->last_meal = millisec_time();
	pthread_mutex_unlock(&philo->data->eat_locker);
	pthread_mutex_unlock(&philo->data->fork_locker[philo->rigth_fork]);
	pthread_mutex_unlock(&philo->data->fork_locker[philo->left_fork]);
}

void	*start_simulation(void *pointer)
{
	t_philo	*temp_philo;

	temp_philo = (t_philo *)pointer;
	if (temp_philo->number % 2 == 0)
		usleep(temp_philo->data->time_to_eat * 800);
	while (true)
	{
		if (change_end_flag(temp_philo, false))
			return (0);
		start_eating(temp_philo);
		print_action(temp_philo, "is sleeping");
		advance_time(temp_philo, temp_philo->data->time_to_sleep);
		print_action(temp_philo, "is thinking");
		if (temp_philo->data->number_philos % 2 \
			&& temp_philo->data->number_philos <= 100)
			advance_time(temp_philo, temp_philo->data->time_to_eat);
	}
	return (0);
}
