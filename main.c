/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:32:33 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/16 13:18:40 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int arc, char **argv)
{
    t_philo philo[MAX_NUM];
    t_data data;
    pthread_t monitor;

    if (arc < 5 || arc > 6)
    {
        write(2, "Error: Invalid number of arguments\n", 36);
        return (1);
    }
    if (arc == 5 || arc == 6)
    {
        if (check_args(argv))
            return (1);
        if (overflow_check(argv))
            return (1);
        init_data(&data, argv);
        init_forks(data.forks_array, data.num_philos);
        init_philos(philo, &data);
        creat_threads(philo, &data);
    }
    return (0);
}
