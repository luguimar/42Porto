/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:37:05 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./philo.h"

int	ft_init_memory(t_info *new)
{
	if (pthread_mutex_init(&new->end, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&new->full, NULL))
	{
		pthread_mutex_destroy(&new->end);
		return (EXIT_FAILURE);
	}
	new->philo = (t_phi *) malloc (sizeof(t_phi) * new->phi_nbr);
	if (!new->philo)
	{
		ft_clean_mutexes(new);
		return (EXIT_FAILURE);
	}
	if (ft_finish_memory(new))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	ft_finish_memory(t_info *new)
{
	new->fork = (pthread_mutex_t *) malloc (sizeof(pthread_mutex_t) \
	* new->phi_nbr);
	if (!new->fork)
	{
		free(new->philo);
		ft_clean_mutexes(new);
		return (EXIT_FAILURE);
	}
	new->end_thr = (pthread_t *) malloc (sizeof(pthread_mutex_t));
	if (!new->end_thr)
	{
		free(new->philo);
		free(new->fork);
		ft_clean_mutexes(new);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_memory_set(t_info *new)
{
	int	i;

	i = 0;
	if (ft_init_memory(new))
	{
		printf("Fail creating dinamic memory.\n");
		return (EXIT_FAILURE);
	}
	while (i < new->phi_nbr)
	{
		if (pthread_mutex_init(&new->fork[i], NULL))
		{
			while ((i - 1) >= 0)
			{
				pthread_mutex_destroy(&new->fork[i - 1]);
				i--;
			}
			free(new->philo);
			free(new->fork);
			ft_clean_mutexes(new);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_get_defs(t_info *new, int argc, char **argv)
{
	if (!ft_atoi(argv[1]) || !ft_atoi(argv[2]) || \
	!ft_atoi(argv[3]) || !ft_atoi(argv[4]))
		return (EXIT_FAILURE);
	else
	{
		new->phi_nbr = ft_atoi(argv[1]);
		new->time_to_die = ft_atoi(argv[2]);
		new->time_to_eat = ft_atoi(argv[3]);
		new->time_to_sleep = ft_atoi(argv[4]);
	}
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (EXIT_FAILURE);
		else
			new->meals_to_eat_all = ft_atoi(argv[5]);
	}
	else
		new->meals_to_eat_all = 0;
	new->the_end = 0;
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_info	new;

	if (argc != 5 && argc != 6)
	{
		printf("The number of arguments must be 4 or 5\nUsage: \
./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	if (ft_check_arg_value(argc, argv))
		return (EXIT_FAILURE);
	if (ft_get_defs(&new, argc, argv))
	{
		printf("The args must be integers\n");
		return (EXIT_FAILURE);
	}
	if (ft_memory_set(&new))
		return (EXIT_FAILURE);
	ft_philosopher_info(&new);
	if (ft_create_philosophers(&new))
		return (EXIT_FAILURE);
	ft_clean(&new, new.phi_nbr);
	return (0);
}
