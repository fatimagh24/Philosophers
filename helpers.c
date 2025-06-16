/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:32:03 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/16 13:17:56 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_args(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (ft_isdigit(argv[i][0]) == 0 || ft_atoi(argv[i]) <= 0)
        {
            write(2, "Error: Invalid argument\n", 24);
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
            write(2 , "Argument overflow\n", 20);
			return (1);
		}
		i++;
	}
	if (argv[i] && ft_atoi(argv[5]) > INT_MAX)
	{
		write(2 , "Argument overflow\n", 20);
		return (1);
	}
	return (0);
}


int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
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
	}
	return (0);
}

int is_dead(t_philo *philo)
{
    if(((int)get_current_time() - philo->last_meal_t) > philo->data->die_t)
    {
        pthread_mutex_lock(&philo->data->print_lock);
        printf("%lld %d died\n", get_current_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print_lock);
        philo->state = DEAD;
        philo->data->sim_flag = 0;
        return (1);
    }
    return (0);
}
