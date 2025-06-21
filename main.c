/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:32:33 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/21 13:20:55 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int arc, char **argv)
{
	t_philo		philo[MAX_NUM];
	t_data		data;
	pthread_t	monitor;

	if (arc < 5 || arc > 6)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (1);
	}
	if (check_args(argv))
		return (1);
	if (overflow_check(argv))
		return (1);
	if (init_data(&data, argv) == 1)
		return (1);
	if (init_forks(data.forks_array, data.num_philos) == 1)
	{
		free(data.forks_array);
		pthread_mutex_destroy(&data.print_lock);
		return (1);
	}
	init_philos(philo, &data);
	creat_threads(philo, &data);
	ft_free(&data);
	return (0);
}
