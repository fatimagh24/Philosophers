/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:34:28 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/21 12:35:35 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(t_data *data, char **argv)
{
	data->num_philos = ft_atoi(argv[1]);
	if (data->num_philos <= 0 || data->num_philos > MAX_NUM)
	{
		ft_putstr_fd("Error: Invalid number of philosophers\n", 2);
		return (1);
	}
	data->die_t = ft_atoi(argv[2]);
	data->eat_t = ft_atoi(argv[3]);
	data->sleep_t = ft_atoi(argv[4]);
	if (check_time_values(data) == 1)
		return (1);
	if (argv[5] != NULL)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = -1;
	data->start_time = get_current_time();
	data->forks_array = malloc(sizeof(t_fork) * data->num_philos);
	if (!data->forks_array)
		return (1);
	data->sim_flag = 1;
	pthread_mutex_init(&data->print_lock, NULL);
	data->philo = NULL;
	return (0);
}

void	init_philos(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal_t = data->start_time;
		philos[i].data = data;
		philos[i].state = THINKING;
		philos[i].l_fork = &data->forks_array[i];
		philos[i].r_fork = &data->forks_array[(i + 1) % data->num_philos];
		i++;
	}
}

int	init_forks(t_fork *forks, int num_forks)
{
	int	i;

	i = 0;
	while (i < num_forks)
	{
		forks[i].id = i + 1;
		if (pthread_mutex_init(&forks[i].mutex, NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
