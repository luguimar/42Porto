/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:02:24 by aamaral-          #+#    #+#             */
/*   Updated: 2024/01/09 21:02:26 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	unsigned int	integer;

	integer = 0;
	if (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			return (printf("arg must be a posivite number \n") * -1);
		str++;
	}
	if (*str == '0')
		return (printf("%s", "arg cannot be zero\n") * -1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (printf("arg inserted not a positive integer\n") * -1);
		else
			integer = (integer * 10) + *str - '0';
		str++;
	}
	return (integer); 
}

int	thinking_alone(t_data *data)
{
	printf("%d 1 has taken a fork\n", 0);
	usleep(data->time_to_die * 1000);
	return (printf("%d 1 died\n", data->time_to_die));
}

long long	millisec_time(void)
{
	struct timeval	precise_time;

	if (gettimeofday(&precise_time, NULL))
		return (-1);
	return ((precise_time.tv_sec * 1000 + precise_time.tv_usec / 1000));
}

void	advance_time(t_philo *philo, long long action_time)
{
	long long	begin;

	begin = millisec_time();
	while (!change_end_flag(philo, false) && \
		(millisec_time() - begin) < action_time)
		usleep(10);
}

int	end_full_condition(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->eat_locker);
	if (millisec_time() - philo->start_meal >= philo->data->time_to_die && \
		!philo->eating_flag)
	{
		print_action(philo, "died");
		change_end_flag(philo, true);
		pthread_mutex_unlock(&philo->data->eat_locker);
		return (true);
	}
	else if (philo->data->times_must_eat > 0
		&& philo->eat_counter >= philo->data->times_must_eat)
	{
		philo->data->ate_enough++;
		if (philo->data->ate_enough >= philo->data->number_philos)
		{
			change_end_flag(philo, true);
			print_action(philo, "full");
			pthread_mutex_unlock(&philo->data->eat_locker);
			return (true);
		}
	}
	pthread_mutex_unlock(&philo->data->eat_locker);
	return (false);
}
