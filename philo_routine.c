/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:33:07 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/16 13:16:15 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int philo_thinking(t_philo *philo)
{
    if (is_dead(philo))
        return(1);
    pthread_mutex_lock(&philo->data->print_lock);
    printf("%lld philo %d is thinking\n", get_current_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->print_lock);
    return (0);
}

int philo_eating(t_philo *philo)
{
    if (is_dead(philo))
        return(1);
    pthread_mutex_lock(&philo->data->print_lock);
    pthread_mutex_lock(&philo->l_fork->mutex);
    printf("%lld philo %d has taken a left fork\n", get_current_time() - philo->data->start_time, philo->id);
    pthread_mutex_lock(&philo->r_fork->mutex);
    printf("%lld philo %d has taken a right fork\n", get_current_time() - philo->data->start_time, philo->id);
    printf("%lld philo %d is eating\n", get_current_time() - philo->data->start_time, philo->id);
    pthread_mutex_unlock(&philo->data->print_lock);
    philo->state = EATING;
	philo->last_meal_t = get_current_time();
	ft_usleep(philo, philo->data->eat_t);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->l_fork->mutex);
	pthread_mutex_unlock(&philo->r_fork->mutex);
    return (0);
}

int philo_sleeping(t_philo *philo)
{
    if (is_dead(philo))
        return(1);
    pthread_mutex_lock(&philo->data->print_lock);
	printf("%lld philo %d is sleeping\n", get_current_time() - philo->data->start_time, philo->id);
	pthread_mutex_unlock(&philo->data->print_lock);
	philo->state = SLEEPING;
	ft_usleep(philo, philo->data->sleep_t);
    return (0);
}

long	time_diff(long past, long now)
{
	return (now - past);
}
