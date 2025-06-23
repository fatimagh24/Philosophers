/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:35:44 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/23 11:58:21 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_threads(t_philo *philos, t_data *data)
{
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine,
				&philos[i]) != 0)
		{
			ft_putstr_fd("Error: Failed to create thread\n", 2);
			return ;
		}
		i++;
	}
	join_threads(philos, data);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
	{
		if (philo_thinking(philo) == 1)
			return (NULL);
		while (!dead_check(philo))
			;
		return (NULL);
	}
	while (get_sim_flag(philo->data, 1) == 1)
	{
		if (philo_eating(philo) == 1)
			return (NULL);
		if (philo_thinking(philo) == 1)
			return (NULL);
		if (philo_sleeping(philo) == 1)
			return (NULL);
		if (finished_meals(philo) == 1)
			return (NULL);
	}
	return (NULL);
}

void	join_threads(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}

int	get_sim_flag(t_data *data, int new_f)
{
	int	flag;

	pthread_mutex_lock(&data->sim_lock);
	flag = data->sim_flag;
	if (new_f == 0)
		data->sim_flag = new_f;
	pthread_mutex_unlock(&data->sim_lock);
	return (flag);
}

int	finished_meals(t_philo *philo)
{
	if (philo->data->num_meals != -1
		&& philo->meals_eaten >= philo->data->num_meals)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		printf("%lld philo %d has finished eat %d meals \n", get_current_time()
			- philo->data->start_time, philo->id, philo->meals_eaten);
		pthread_mutex_unlock(&philo->data->print_lock);
		return (1);
	}
	return (0);
}
