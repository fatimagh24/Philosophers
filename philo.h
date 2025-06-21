/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:47:59 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/21 13:20:48 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_NUM 200

typedef struct s_data	t_data;

typedef enum philo_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}						t_philo_state;

typedef struct s_fork
{
	pthread_mutex_t		mutex;
	int					id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	int					meals_eaten;
	t_philo_state		state;
	long long			last_meal_t;
	pthread_t			thread;
	t_fork				*l_fork;
	t_fork				*r_fork;
	t_data				*data;
	pthread_mutex_t		dead;
}						t_philo;

typedef struct s_data
{
	int					num_philos;
	int					die_t;
	int					eat_t;
	int					sleep_t;
	int					num_meals;
	int					sim_flag;
	long long			start_time;
	t_fork				*forks_array;
	pthread_mutex_t		print_lock;
	t_philo				*philo;
}						t_data;

int						init_data(t_data *data, char **argv);
void					init_philos(t_philo *philos, t_data *data);
int						init_forks(t_fork *forks, int num_forks);
int						get_current_time(void);
void					*philo_routine(void *arg);
void					creat_threads(t_philo *philos, t_data *data);
int						check_args(char **argv);
void					join_threads(t_philo *philos, t_data *data);
void					ft_putstr_fd(char *s, int fd);
int						ft_sleep(t_philo *philo, size_t ms);
int						dead_check(t_philo *philo);
int						philo_thinking(t_philo *philo);
int						philo_eating(t_philo *philo);
int						philo_sleeping(t_philo *philo);
void					ft_free(t_data *data);
int						overflow_check(char **argv);
int						get_sim_flag(t_data *data, int new_f);
int						check_time_values(t_data *data);
int						finished_meals(t_philo *philo);
int						ft_isdigit(int c);
int						ft_atoi(const char *s);
#endif
