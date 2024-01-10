/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:36:55 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:37:05 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./philo.h"

int	ft_control_arg_int(int argc, char *number)
{
	long long	num;
	int			i;

	i = 1;
	while (i < argc - 1)
	{
		num = ft_atoll(number);
		if (num > 2147483647 || ft_strlen(number) > 10)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_digits(char *number)
{
	int	i;
	int	len;

	len = ft_strlen(number);
	i = 0;
	while (i < len)
	{
		if (!ft_isdigit(number[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_arg_value(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i <= argc - 1)
	{
		if (ft_check_digits(argv[i]))
		{
			printf("You can only test valid x numbers.\n");
			return (EXIT_FAILURE);
		}
		if (ft_control_arg_int(argc, argv[i]))
		{
			printf("You can only test int numbers.\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf("The program must have at least one Philosopher.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_clean_mutexes(t_info *new)
{
	pthread_mutex_destroy(&new->end);
	pthread_mutex_destroy(&new->full);
}

void	ft_clean(t_info *new, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		pthread_mutex_destroy(&new->fork[j]);
		j++;
	}
	ft_clean_mutexes(new);
	free(new->fork);
	free(new->end_thr);
	free(new->philo);
}
