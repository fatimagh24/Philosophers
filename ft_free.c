/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:36:27 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/16 13:22:32 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_free(t_data *data, t_philo *philos)
{
    int i;

    if (data->forks_array)
    {
        i = 0;
        while (i < data->num_philos)
        {
            pthread_mutex_destroy(&data->forks_array[i].mutex);
            i++;
        }
        free(data->forks_array);
    }
    if (philos)
    {
        i = 0;
        while (i < data->num_philos)
        {
            pthread_mutex_destroy(&philos[i].l_fork->mutex);
            pthread_mutex_destroy(&philos[i].r_fork->mutex);
            i++;
        }
        free(philos);
    }
    pthread_mutex_destroy(&data->print_lock);
    
    //free(data);
}

void ft_free_all(t_data *data, t_philo *philos)
{
    // printf("hggggggggg\n");
    ft_free(data, philos);
    exit(EXIT_SUCCESS);
}
