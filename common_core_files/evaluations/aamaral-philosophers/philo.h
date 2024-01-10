/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamaral- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:03:28 by aamaral-          #+#    #+#             */
/*   Updated: 2024/01/09 21:03:30 by aamaral-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
	int				number;
	int				eat_counter;
	int				left_fork;
	int				rigth_fork;
	long long		last_meal;
	long long		start_meal;
	struct s_data	*data;
	pthread_t		thread;
	int				eating_flag;
}					t_philo;

typedef struct s_data
{
	int				number_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_must_eat;
	int				ate_enough;
	int				end_flag;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork_locker;
	pthread_mutex_t	print_locker;
	pthread_mutex_t	eat_locker;
	pthread_mutex_t	end_locker;
}					t_data;

/* actions */

int			change_end_flag(t_philo *philo, int must_end);
void		print_action(t_philo *philo, const char *action);
void		start_eating(t_philo *philo);
void		*start_simulation(void *pointer);

/* exit */

void		free_philofork_malloc(t_data *data);
void		destroy_mutex(t_data *data);
void		end_simulation(t_data *data);
int			destroy(char *msg, t_data *data, int option);

/* philo */

int			check_treat_arg(int argc, char **argv, t_data *data);
void		init_philo(t_data *data);
int			create_thread_mutex(t_data *data);
void		start_simulation_monitor(t_data *data);

/* utils */

int			ft_atoi(const char *str);
int			thinking_alone(t_data *data);
long long	millisec_time(void);
void		advance_time(t_philo *philo, long long action_time);
int			end_full_condition(t_philo *philo);

#endif
