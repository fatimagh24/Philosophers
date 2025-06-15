/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:32:33 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/15 17:44:05 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int arc, char **argv)
{
    t_philo philo[MAX_NUM];
    t_data data;

    if (arc <= 5 || arc > 6)
    {
        write(2, "Error: Invalid number of arguments\n", 36);
        return (1);
    }
    check_args(argv);
    init_data(&data, argv);
    // init_forks(data.forks_array, data.num_philos);
    // init_philos(philo, &data);
    // create_threads(philo, &data);
    return (0);
}

void check_args(char **argv)
{
    int i;

    i = 1;
    while (argv[i])
    {
        if (ft_isdigit(argv[i][0]) || ft_atoi(argv[i]) <= 0)
        {
            write(2, "Error: Invalid argument\n", 24);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}  

void init_data(t_data *data, char **argv)
{
    data->num_philos = ft_atoi(argv[1]);
    if (data->num_philos <= 0 || data->num_philos > MAX_NUM)
    {
        write(2, "Error: Invalid number of philosophers\n", 39);
        exit(EXIT_FAILURE);
    }
    data->die_t = ft_atoi(argv[2]);
    data->eat_t = ft_atoi(argv[3]);
    data->sleep_t = ft_atoi(argv[4]);
    if (argv[5] != NULL)
        data->num_meals = ft_atoi(argv[5]);
    else
        data->num_meals = -1;
    data->start_time = get_current_time();
    data->forks_array = malloc(sizeof(t_fork) * data->num_philos);
    if(!data->forks_array)
    {
        write(2, "Error: Memory allocation failed\n", 33);
        exit(EXIT_FAILURE);
    }
    data->sim_flag = 1;
    pthread_mutex_init(&data->print_lock, NULL);
    data->philo = NULL;
}

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void init_philos(t_philo *philos, t_data *data)
{
    int i;
    
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
        pthread_mutex_init(&philos[i].l_fork->mutex, NULL);
        pthread_mutex_init(&philos[i].r_fork->mutex, NULL);
        i++;
    }
}

void init_forks(t_fork *forks, int num_forks)
{
    int i;

    i = 0;
    while (i < num_forks)
    {
        forks[i].id = i + 1;
        pthread_mutex_init(&forks[i].mutex, NULL);
        i++;
    }
}

void    creat_threads(t_philo *philos, t_data *data)
{
    int i;

    i = 0;
    // while (i < data->num_philos)
    // {
    //     if (pthread_create(&philos[i].thread, NULL, &philo_routine, &philos[i]) != 0)
    //     {
    //         write(2, "Error: Failed to create thread\n", 32);
    //         exit(1);
    //     }
    //     i++;
    // }
}

void philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    // while (philo->data->sim_flag)
    // {
    //     pthread_mutex_lock(&philo->data->print_lock);
    //     printf("%d  %d is thinking\n", get_current_time(), philo->id);
    // }
}
