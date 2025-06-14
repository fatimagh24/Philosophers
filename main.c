/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fghanem <fghanem@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:48:05 by fghanem           #+#    #+#             */
/*   Updated: 2025/06/14 17:14:22 by fghanem          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_data(t_data *data, char **arv)
{
    data = malloc(sizeof(t_data));
    if (!data)
    {
        printf("%s\n", "ERROR: faild to allocate");
        exit(1);
    }
    data->num_philos = ft_atol(arv[1]);
    if (data->num_philos <= 0 || data->num_philos > MAX_NUM)
    {
        printf("%s\n", "ERROR: invalid number of philosophers");
        exit(1);
    }
	data->die_t = ft_atol(arv[2]) * 1000;
	data->eat_t = ft_atol(arv[3]) * 1000;
	data->sleep_t = ft_atol(arv[4]) * 1000;
    // data->forks_array = malloc(sizeof(t_fork) * data->num_philos);
    // if (!data->forks_array)
    // {
    //     printf("%s\n", "ERROR: faild to allocate");
    //     exit(1);
    // }
    // data->sim_flag = 0;
    // data->start_time = 0;
    // if (arv[5])
    //     data->num_meals = ft_atol(arv[5]);
    // else
    //     data->num_meals = -1;
    // pthread_mutex_init(&data->print_lock, NULL);
}

void    init_philo(t_data *data)
{
    t_philo     *philo;

    philo = malloc(sizeof(t_philo));
    if (!philo)
        printf("%s\n", "ERROR: faild to allocate");
    philo->id = 0;
    philo->meals_eaten = 0;
    philo->last_meal_t = 0;
    philo->data = data;
    // philo->l_fork = &data->forks_array[philo->id];
    // philo->r_fork = &data->forks_array[(philo->id + 1) % data->num_philos];
    // philo->state = THINKING;
    // pthread_mutex_init(&philo->l_fork->mutex, NULL);
    // pthread_mutex_init(&philo->r_fork->mutex, NULL);
    // philo->l_fork->id = philo->id;
    // philo->r_fork->id = (philo->id + 1) % data->num_philos;
    data->philo = philo;
}


void    creat_thread(t_data *data, t_philo philos[MAX_NUM])
{
    int i;

    i = 0;
    // while (i < data->num_philos)
    // {
    //     pthread_create(&philos[i], NULL, NULL, NULL);
    //     i++;
    // }
}

int	main(int arc, char **arv)
{
	t_data	data;
    t_philo philos[MAX_NUM];
	
	if (arc == 5 || arc == 6)
	{
        init_data(&data, arv);
        init_philo(&data);
        // creat_thread(&data, philos);
	}
	else
		printf("%s\n", "ERROR:\n few arguments");
	return (0);
}


// long long get_current_time()
// {
// 	struct timeval time;
// 	gettimeofday(&time, NULL);
// 	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
// }

// long long timestamp(t_data *data)
// {
// 	return get_current_time() - data->start_time;
// }

// void safe_print(t_philo *philo, char *msg)
// {
// 	pthread_mutex_lock(&philo->data->print_lock);
// 	if (!philo->data->sim_flag)
// 		printf("%lld %d %s\n", timestamp(philo->data), philo->id + 1, msg);
// 	pthread_mutex_unlock(&philo->data->print_lock);
// }

// void *philo_routine(void *arg)
// {
// 	t_philo *philo = (t_philo *)arg;

// 	if (philo->id % 2)
// 		usleep(100);
// 	while (!philo->data->sim_flag)
// 	{
// 		safe_print(philo, "is thinking");
// 		pthread_mutex_lock(&philo->l_fork->mutex);
// 		safe_print(philo, "has taken a fork");
// 		pthread_mutex_lock(&philo->r_fork->mutex);
// 		safe_print(philo, "has taken a fork");

// 		safe_print(philo, "is eating");
// 		philo->last_meal_t = get_current_time();
// 		philo->meals_eaten++;
// 		usleep(philo->data->eat_t);

// 		pthread_mutex_unlock(&philo->r_fork->mutex);
// 		pthread_mutex_unlock(&philo->l_fork->mutex);

// 		safe_print(philo, "is sleeping");
// 		usleep(philo->data->sleep_t);
// 	}
// 	return NULL;
// }

// void monitor(t_data *data)
// {
// 	int i;

// 	while (!data->sim_flag)
// 	{
// 		i = 0;
// 		while (i < data->num_philos)
// 		{
// 			if ((get_current_time() - data->philos[i].last_meal_t) > data->die_t)
// 			{
// 				pthread_mutex_lock(&data->print_lock);
// 				printf("%lld %d died\n", timestamp(data), data->philos[i].id + 1);
// 				data->sim_flag = 1;
// 				pthread_mutex_unlock(&data->print_lock);
// 				return;
// 			}
// 			i++;
// 		}
// 		usleep(1000);
// 	}
// }

// void init_data(t_data *data, char **arv)
// {
//     int i;

//     i = 0;
// 	memset(data, 0, sizeof(t_data));
// 	data->num_philos = atoi(arv[1]);
// 	data->die_t = atoi(arv[2]) * 1000;
// 	data->eat_t = atoi(arv[3]) * 1000;
// 	data->sleep_t = atoi(arv[4]) * 1000;
// 	data->num_meals = (arv[5]) ? atoi(arv[5]) : -1;
// 	pthread_mutex_init(&data->print_lock, NULL);
// 	data->forks_array = malloc(sizeof(t_fork) * data->num_philos);
// 	memset(data->forks_array, 0, sizeof(t_fork) * data->num_philos);
// 	while (i < data->num_philos)
//     {
// 		pthread_mutex_init(&data->forks_array[i].mutex, NULL);
//         i++;
//     }
//     data->start_time = get_current_time();
// }

// void init_philos(t_data *data)
// {
//     int i;

//     i = 0;
// 	while (i < data->num_philos)
// 	{
// 		t_philo *p = &data->philos[i];
// 		p->id = i;
// 		p->data = data;
// 		p->l_fork = &data->forks_array[i];
// 		p->r_fork = &data->forks_array[(i + 1) % data->num_philos];
// 		p->last_meal_t = get_current_time();
// 		p->meals_eaten = 0;
//         i++;
// 	}
// }

// void create_threads(t_data *data)
// {
//     int i;

//     i = 0;
// 	while (i < data->num_philos)
//     {
// 		pthread_create(&data->philos[i].thread, NULL, philo_routine, &data->philos[i]);
//         i++;
//     }
// }

// void join_threads(t_data *data)
// {
//     int i;

//     i = 0;
// 	while (i < data->num_philos)
//     {
// 		pthread_join(data->philos[i].thread, NULL);
//         i++;
//     }
// }

// void destroy_all(t_data *data)
// {
//     int i;

//     i = 0;
// 	while (i < data->num_philos)
//     {
// 		pthread_mutex_destroy(&data->forks_array[i].mutex);
//         i++;
//     }
//     pthread_mutex_destroy(&data->print_lock);
// 	free(data->forks_array);
// }

// int main(int arc, char **arv)
// {
// 	t_data data;

// 	if (arc == 5 || arc == 6)
// 	{
// 		init_data(&data, arv);
// 		init_philos(&data);
// 		create_threads(&data);
// 		monitor(&data);
// 		join_threads(&data);
// 		destroy_all(&data);
// 	}
// 	else
// 		write(2, "ERROR: Wrong arguments\n", 25);
// 	return 0;
// }
