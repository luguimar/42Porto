/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:37:05 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

long	ft_current_time(void)
{
	struct timeval	current_time;
	long			current;

	if (gettimeofday(&current_time, NULL))
		return (0);
	current = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	return (current);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_reset(int *i, int *j, int time)
{
	*i = 0;
	*j = 0;
	usleep(time);
}

void	ft_unlock_two_forks(t_phi *philo)
{
	pthread_mutex_unlock(philo->first_fork);
	pthread_mutex_unlock(philo->second_fork);
}
