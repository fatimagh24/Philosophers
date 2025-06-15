/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:59 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/15 17:42:26 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include "libft/libft.h"



#define MAX_NUM 200

typedef struct s_data t_data;

typedef enum philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_philo_state;

typedef struct s_fork
{
    pthread_mutex_t  mutex;
    int             id;
}   t_fork;

typedef struct	s_philo
{
	int	id;
	int	meals_eaten;
	t_philo_state state;
	long long	last_meal_t;
	pthread_t		thread;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_data			*data;
}	t_philo;

typedef struct	s_data
{
	int	num_philos;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	num_meals;
	int	sim_flag;
	long long		start_time;
	t_fork					*forks_array;
	pthread_mutex_t			print_lock;
    t_philo					*philo;
}	t_data;

void	init_data(t_data *data, char **argv);
void	init_philos(t_philo *philos, t_data *data);
void	init_forks(t_fork *forks, int num_forks);
int		get_current_time(void);
void	philo_routine(void *arg);
void	creat_threads(t_philo *philos, t_data *data);
void check_args(char **argv);


#endif
