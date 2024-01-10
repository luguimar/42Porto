/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:37:05 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./philo.h"

int	ft_print_message(char *str, t_phi *philo)
{
	pthread_mutex_lock(&philo->info->end);
	if (philo->info->the_end == 1)
	{
		pthread_mutex_unlock(&philo->info->end);
		return (0);
	}
	printf("%li %i %s\n", ft_current_time() - philo->info->start, \
philo->id_phi, str);
	pthread_mutex_unlock(&philo->info->end);
	return (1);
}

int	ft_lock_second_fork(t_phi *philo)
{
	pthread_mutex_lock(philo->second_fork);
	if (!ft_print_message("has taken a fork", philo) || \
		!ft_print_message("is eating", philo))
	{
		ft_unlock_two_forks(philo);
		return (0);
	}
	pthread_mutex_lock(&philo->info->full);
	philo->meal_time = ft_current_time();
	pthread_mutex_unlock(&philo->info->full);
	usleep(philo->info->time_to_eat * 1000);
	pthread_mutex_lock(&philo->info->full);
	philo->meals_eated++;
	pthread_mutex_unlock(&philo->info->full);
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
	return (1);
}

int	ft_eat(t_phi *philo)
{
	pthread_mutex_lock(philo->first_fork);
	if (philo->info->phi_nbr == 1)
	{
		ft_print_message("has taken a fork", philo);
		usleep(philo->info->time_to_die * 1000);
		pthread_mutex_unlock(philo->first_fork);
		return (0);
	}
	if (!ft_print_message("has taken a fork", philo))
	{
		pthread_mutex_unlock(philo->first_fork);
		return (0);
	}
	if (!ft_lock_second_fork(philo))
		return (0);
	return (1);
}

int	ft_sleep(t_phi *philo)
{
	usleep(300);
	if (!ft_print_message("is sleeping", philo))
		return (0);
	usleep(philo->info->time_to_sleep * 1000);
	return (1);
}

int	ft_think(t_phi *philo)
{
	if (!ft_print_message("is thinking", philo))
		return (0);
	return (1);
}
