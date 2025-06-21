/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:07 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/21 16:02:50 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_thinking(t_philo *philo)
{
	if (dead_check(philo))
		return (1);
	pthread_mutex_lock(&philo->data->print_lock);
	if (get_sim_flag(philo->data, 1))
	{
		printf("%lld %d is thinking\n", get_current_time()
			- philo->data->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
	return (0);
}

int	lock_forks_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->l_fork->mutex);
		if (dead_check(philo))
		{
			pthread_mutex_unlock(&philo->l_fork->mutex);
			return (1);
		}
		pthread_mutex_lock(&philo->r_fork->mutex);
	}
	else
	{
		pthread_mutex_lock(&philo->r_fork->mutex);
		if (dead_check(philo))
		{
			pthread_mutex_unlock(&philo->r_fork->mutex);
			return (1);
		}
		pthread_mutex_lock(&philo->l_fork->mutex);
	}
	return (0);
}

void	unlock_forks_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->r_fork->mutex);
		pthread_mutex_unlock(&philo->l_fork->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->l_fork->mutex);
		pthread_mutex_unlock(&philo->r_fork->mutex);
	}
}

int	philo_eating(t_philo *philo)
{
	if (dead_check(philo))
		return (1);
	if (lock_forks_philo(philo))
		return (1);
	pthread_mutex_lock(&philo->data->print_lock);
	if (get_sim_flag(philo->data, 1))
	{
		printf("%lld %d has taken a left fork\n", get_current_time()
			- philo->data->start_time, philo->id);
		printf("%lld %d has taken a right fork\n", get_current_time()
			- philo->data->start_time, philo->id);
		printf("%lld %d is eating\n", get_current_time()
			- philo->data->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
	philo->state = EATING;
	philo->last_meal_t = get_current_time();
	ft_sleep(philo, philo->data->eat_t);
	philo->meals_eaten++;
	unlock_forks_philo(philo);
	return (0);
}

int	philo_sleeping(t_philo *philo)
{
	if (dead_check(philo))
		return (1);
	pthread_mutex_lock(&philo->data->print_lock);
	if (get_sim_flag(philo->data, 1))
	{
		printf("%lld %d is sleeping\n", get_current_time()
			- philo->data->start_time, philo->id);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
	philo->state = SLEEPING;
	ft_sleep(philo, philo->data->sleep_t);
	return (0);
}
