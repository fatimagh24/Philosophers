/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:59 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/14 17:09:59 by fghanem          ###   ########.fr       */
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

// typedef enum philo_state
// {
// 	THINKING,
// 	EATING,
// 	SLEEPING,
// 	DEAD
// } t_philo_state;

// typedef struct s_fork
// {
// 	pthread_mutex_t mutex;
// 	int id;
// } t_fork;

// typedef struct s_philo
// {
// 	int id;
// 	int meals_eaten;
// 	long long last_meal_t;
// 	pthread_t thread;
// 	t_data *data;
// 	t_fork *l_fork;
// 	t_fork *r_fork;
// 	t_philo_state state;
// } t_philo;

// typedef struct s_data
// {
// 	int num_philos;
// 	int die_t;
// 	int eat_t;
// 	int sleep_t;
// 	int num_meals;
// 	int sim_flag;
// 	long long start_time;
// 	t_fork *forks_array;
// 	t_philo philos[MAX_NUM];
// 	pthread_mutex_t print_lock;
// } t_data;



// #define   MAX_NUM 200

// typedef struct s_data t_data;

typedef enum philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	LEFT_FORK,
	RIGHT_FORK,
	WAITING,
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
	long long	last_meal_t;
	pthread_t		thread;
	t_fork			*l_fork;
	t_fork			*r_fork;
	t_data			*data;
	t_philo_state	state;
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

long ft_atol(char *s);
void    init_data(t_data *data, char **arv);
void    init_philo(t_data *data);

#endif
