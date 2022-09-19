/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:37:53 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/19 16:55:10 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int laod_philosophers(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_create(&data->ph[i].id_t, NULL, philosophers, &data->ph[i]) != 0)
        {
            exit_error(data, "philo: Failed to create a thread!", 2);
            return (1);
        }
        i++;
    }
    return (0);
}

int laod_checkers(int ac, t_data *data)
{
    int i;

    i = 0;
    if (ac == 6)
    {
        if (pthread_create(&data->eat_t, NULL, check_eat_times, data) != 0)
        {
            exit_error(data, "philo: Failed to create a thread!", 2);
            return (1);
        }
    }
    if (pthread_create(&data->dead_t, NULL, check_dead, data) != 0)
    {
        exit_error(data, "philo: Failed to create a thread!", 1);
        return(1);
    }
    return (0);
}

int init_mutex(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_mutex_init(&data->ph[i].left_fork, NULL) != 0)
        {
            exit_error(data, "philo: Failed to init mutex", 1);
            return (1);
        }
        data->ph[i].right_fork = &data->ph[(i + 1) % (data->nbr_of_philo)].left_fork;
        //printf("%d\n\n\n\n", (i + 1) % (data->nbr_of_philo));
        data->ph[i].id_n = i;
        data->ph[i].data = data;
        data->ph[i].meals = 0;
        data->ph[i].last_meal = 0;
        i++;
    }
    if (pthread_mutex_init(&data->lock_1, NULL) != 0)
    {
        exit_error(data, "philo: Failed to init mutex", 1);
        return (1);
    }
    return (0);
}

int init_data(int ac, t_data *data, char **av)
{
    data->nbr_of_philo = ft_atoi(av[1]);
    if (data->nbr_of_philo == 0 || data->nbr_of_philo >= 200)
    {
        exit_error(data, "philo: Invalid number of philosophers", 0);
        return (1);
    }
    data->dead = 0;
    data->time_init = 0;
    data->eat_times = 0;
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->eat_times = ft_atoi(av[5]);
    data->ph = malloc(sizeof(t_philo) * data->nbr_of_philo);
    if (!data->ph)
    {
        exit_error(data, "philo: allocation failed!", 0);
        return (1);
    }
    if (gettimeofday(&data->time, NULL) != 0)
    {
        exit_error(data, "philo: Failed to get time of day!", 1);
        return (1);
    }
    data->time_init = data->time.tv_sec*1000 + data->time.tv_usec/1000;
    return (0);
}

int begin_sim(int ac, t_data *data, char **av)
{
    int i;
    
    i = 0;
    if (init_data(ac, data, av))
        return (1);
    if (init_mutex(data))
        return (1);
    if (laod_checkers(ac, data))
        return (1);
    if (laod_philosophers(data))
        return (1);
    while (i < data->nbr_of_philo)
    {
        if (pthread_detach(data->ph[i].id_t) != 0)
            exit_error(data, "philo: Failed to join a thread!", 1);
        i++;
    }
    return (0);
}