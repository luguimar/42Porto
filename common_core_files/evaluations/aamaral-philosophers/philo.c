/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:02:13 by aamaral-          #+#    #+#             */
/*   Updated: 2024/01/09 21:02:15 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_treat_arg(int argc, char **argv, t_data *data)
{
	if (argc == 6 || argc == 5)
	{
		if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || \
			ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
			return (42);
		data->number_philos = ft_atoi(argv[1]);
		data->time_to_die = ft_atoi(argv[2]);
		data->time_to_eat = ft_atoi(argv[3]);
		data->time_to_sleep = ft_atoi(argv[4]);
		data->end_flag = 0;
		if (argc == 6)
		{
			if (ft_atoi(argv[5]) < 0)
				return (42);
			data->times_must_eat = ft_atoi(argv[5]);
		}
		if (data->number_philos == 1)
			return (thinking_alone(data));
	}
	else
		return (printf("wrong number of arguments. must be 5 or 6\n"));
	return (0);
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->number_philos);
	data->fork_locker = malloc(sizeof(pthread_mutex_t) * data->number_philos);
	if (!data->philo || !data->fork_locker)
		destroy("Error in allocate memory for philo and/or locks", data, 1);
	data->start_time = millisec_time();
	while (i < data->number_philos)
	{
		data->philo[i].number = i + 1;
		data->philo[i].left_fork = i;
		data->philo[i].rigth_fork = (i + 1) % data->number_philos;
		data->philo[i].eat_counter = 0;
		data->philo[i].last_meal = data->start_time;
		data->philo[i].start_meal = data->start_time;
		data->philo[i].eating_flag = 0;
		data->philo[i].data = data;
		i++;
	}
}

int	create_thread_mutex(t_data *data)
{
	int	i;

	if (pthread_mutex_init(&data->eat_locker, NULL))
		return (destroy("Error create eat lock", data, 2));
	if (pthread_mutex_init(&data->print_locker, NULL))
		return (destroy("Error create print lock", data, 2));
	if (pthread_mutex_init(&data->end_locker, NULL))
		return (destroy("Error create end lock", data, 2));
	i = -1;
	while (++i < data->number_philos)
		if (pthread_mutex_init(&data->fork_locker[i], NULL))
			return (destroy("Error at initialize forks locks", data, 2));
	i = -1;
	while (++i < data->number_philos)
		if (pthread_create(&data->philo[i].thread, NULL, \
			start_simulation, &data->philo[i]))
			return (destroy("Error in creating philo thread", data, 3));
	return (0);
}

void	start_simulation_monitor(t_data *data)
{
	int	i;
	int	not_end_flag;

	not_end_flag = 1;
	while (not_end_flag)
	{
		i = 0;
		data->ate_enough = 0;
		while (i < data->number_philos)
		{
			if (not_end_flag && end_full_condition(&data->philo[i]))
				not_end_flag = 0;
			i++;
		}
		usleep(10);
	}
	end_simulation(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_treat_arg(argc, argv, &data))
		return (42);
	init_philo(&data);
	if (create_thread_mutex(&data) == 42)
		return (42);
	start_simulation_monitor(&data);
}
