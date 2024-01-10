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

int	ft_end(t_info *info)
{
	int	i;
	int	j;

	ft_reset(&i, &j, 100);
	while (1)
	{
		if (i >= info->phi_nbr)
			ft_reset(&i, &j, 200);
		pthread_mutex_lock(&info->full);
		if ((long long int)(info->time_to_die) <= (ft_current_time() - \
info->philo[i].meal_time))
		{
			pthread_mutex_unlock(&info->full);
			return (i + 1);
		}
		if (info->meals_to_eat_all != 0 && info->philo[i].meals_eated >= \
info->meals_to_eat_all)
			j++;
		pthread_mutex_unlock(&info->full);
		i++;
		if (j == info->phi_nbr)
			return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

void	*ft_check_end(void *arg_end)
{
	int		i;
	t_info	*info;

	info = (t_info *)arg_end;
	i = ft_end(info);
	pthread_mutex_lock(&info->end);
	info->the_end = 1;
	pthread_mutex_unlock(&info->end);
	if (i > 0)
		printf("%li %i died\n", ft_current_time() - info->start, i);
	return (NULL);
}

void	*ft_routine(void *arg)
{
	t_phi	*tmp_phi;
	t_info	*tmp_info;

	tmp_phi = (t_phi *) arg;
	tmp_info = tmp_phi->info;
	pthread_mutex_lock(&tmp_info->full);
	tmp_phi->meals_eated = 0;
	pthread_mutex_unlock(&tmp_info->full);
	if ((tmp_phi->id_phi) % 2 == 0)
		usleep(2000);
	while (1)
	{
		if (!ft_eat(tmp_phi))
			break ;
		if (!ft_sleep(tmp_phi))
			break ;
		if (!ft_think(tmp_phi))
			break ;
	}
	return (NULL);
}

int	ft_create_philosophers(t_info *info)
{
	int	i;

	i = 0;
	info->start = ft_current_time();
	while (i < info->phi_nbr)
	{
		pthread_create(&info->philo[i].phi_thr, NULL, &ft_routine, (void *) \
&info->philo[i]);
		pthread_mutex_lock(&info->full);
		info->philo[i].meal_time = ft_current_time();
		pthread_mutex_unlock(&info->full);
		i++;
		usleep(200);
	}
	pthread_create(info->end_thr, NULL, &ft_check_end, (void *) info);
	i = 0;
	while (i < info->phi_nbr)
	{
		pthread_join(info->philo[i].phi_thr, NULL);
		i++;
	}
	pthread_join(*info->end_thr, NULL);
	return (EXIT_SUCCESS);
}

int	ft_philosopher_info(t_info *new)
{
	int	i;

	i = 0;
	while (i < new->phi_nbr)
	{
		new->philo[i].id_phi = (i + 1);
		if (i % 2 == 0)
		{
			new->philo[i].first_fork = &new->fork[((i + 1) % new->phi_nbr)];
			new->philo[i].second_fork = &new->fork[i];
		}
		else
		{
			new->philo[i].first_fork = &new->fork[i];
			new->philo[i].second_fork = &new->fork[((i + 1) % new->phi_nbr)];
		}
		new->philo[i].meals_to_eat = 0;
		new->philo[i].info = new;
		i++;
	}
	return (EXIT_SUCCESS);
}
