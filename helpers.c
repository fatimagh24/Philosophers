/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:32:03 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/17 17:26:44 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_time_values(t_data *data)
{
	if (data->die_t < 60 || data->eat_t < 60 || data->sleep_t < 60)
	{
		ft_putstr_fd("Error: Time values must be graeter than 60 ms\n", 2);
		return (1);
	}
	return (0);
}

int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i][0]) == 0 || ft_atoi(argv[i]) <= 0)
		{
			ft_putstr_fd("Error: Invalid argument\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	overflow_check(char **argv)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (ft_atoi(argv[i]) > INT_MAX)
		{
			ft_putstr_fd("Argument overflow\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_usleep(t_philo *philo, size_t ms)
{
	size_t	start;

	(void)philo;
	start = get_current_time();
	while ((get_current_time() - start) < ms)
	{
		if (is_dead(philo))
			break ;
		usleep(100);
	}
	return (0);
}

int	is_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if ((int)(get_current_time() - philo->last_meal_t) > philo->data->die_t)
	{
		if (get_sim_flag(philo->data, 1))
		{
			printf("%lld philo %d died\n",
				get_current_time() - philo->data->start_time, philo->id);
			philo->data->sim_flag = 0;
		}
		pthread_mutex_unlock(&philo->data->print_lock);
		philo->state = DEAD;
		return (1);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
	return (0);
}
