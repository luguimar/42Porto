/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamendoe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 21:37:58 by jamendoe          #+#    #+#             */
/*   Updated: 2023/08/11 21:38:03 by jamendoe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_phi{
	int				id_phi;
	pthread_t		phi_thr;
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	long			meal_time;
	int				meals_to_eat;
	int				meals_eated;
	struct s_info	*info;
}	t_phi;

typedef struct s_info{
	t_phi			*philo;
	pthread_t		*end_thr;
	pthread_mutex_t	*fork;
	pthread_mutex_t	end;
	pthread_mutex_t	full;
	long			start;
	int				phi_nbr;
	int				the_end;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_to_eat_all;
}	t_info;

int			ft_check_arg_value(int argc, char **argv);
int			ft_check_digits(char *number);
size_t		ft_strlen(const char *s);
int			ft_isdigit(int c);
int			ft_control_arg_int(int argc, char *number);
long long	ft_atoll(const char *str);
int			ft_atoi(const char *nptr);
int			ft_get_defs(t_info *new, int argc, char **argv);
int			ft_memory_set(t_info *new);
int			ft_init_memory(t_info *new);
int			ft_finish_memory(t_info *new);
int			ft_philosopher_info(t_info *new);
int			ft_create_philosophers(t_info *info);
long		ft_current_time(void);
int			ft_end(t_info *info);
void		*ft_check_end(void *arg_end);
void		*ft_routine(void *arg);
void		ft_clean_mutexes(t_info *new);
void		ft_clean(t_info *new, int i);
void		ft_reset(int *i, int *j, int time);
int			ft_eat(t_phi *philo);
int			ft_sleep(t_phi *philo);
int			ft_think(t_phi *philo);
void		ft_join_threads(t_info *new);
int			ft_print_message(char *str, t_phi *philo);
int			ft_lock_second_fork(t_phi *philo);
void		ft_unlock_two_forks(t_phi *philo);

#endif
