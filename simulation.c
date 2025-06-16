/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:35:44 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/16 13:23:46 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    creat_threads(t_philo *philos, t_data *data)
{
    int i;
    pthread_t monitor;

    i = 0;
    while (i < data->num_philos)
    {
        if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
        {
            write(2, "Error: Failed to create thread\n", 32);
            ft_free_all(data, philos);
        }
        i++;
    }
    join_threads(philos, data);
}

void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (philo->data->sim_flag)
    {
        if (philo_thinking(philo) == 1)
        {
            ft_free_all(philo->data, philo->data->philo);
            return (NULL);
        }
        if (philo->data->sim_flag == 0)
            break;
        if (philo_eating(philo) == 1)
        {
            ft_free_all(philo->data, philo->data->philo);
            return (NULL);
        }
        if (philo->data->sim_flag == 0)
            break;
        if (philo_sleeping(philo) == 1)
        {
            ft_free_all(philo->data, philo->data->philo);
            return (NULL);
        }
        if (philo->data->sim_flag == 0)
            break;
		if (philo->data->num_meals != -1 && philo->meals_eaten >= philo->data->num_meals)
        {
            pthread_mutex_lock(&philo->data->print_lock);
            printf("%lld philo %d has finished eat %d meals \n", get_current_time() - philo->data->start_time, philo->id, philo->meals_eaten);
            pthread_mutex_unlock(&philo->data->print_lock);
            break ;
        }
    }
    return (NULL);
}

void join_threads(t_philo *philos, t_data *data)
{
    int i = 0;
    while (i < data->num_philos)
    {
        pthread_join(philos[i].thread, NULL);
        i++;
    }
}
