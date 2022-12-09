/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:37:53 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/09 17:48:54 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int laod_philosophers(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_create(&data->ph[i].t_id, NULL, dining_room, &data->ph[i]) != 0)
        {
            end_sim(data, "philo: Failed to create a thread!", 2);
            return (0);
        }
        if (pthread_detach(data->ph[i].t_id) != 0)
        {
            end_sim(data, "philo: failed to detach a thread", 1);
            return (0);
        }
        i++;
    }
    return (1);
}

// *init_philo

int init_mutex(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_mutex_init(&data->ph[i].left_fork, NULL) != 0)
        {
            end_sim(data, "philo: Failed to init mutex", 1);
            return (0);
        }
        if (data->nbr_of_philo > 1)
            data->ph[i].right_fork = &data->ph[(i + 1) % (data->nbr_of_philo)].left_fork;
        data->ph[i].id = i + 1;
        data->ph[i].data = data;
        data->ph[i].meals = 0;
        data->ph[i].last_meal = 0;
        data->ph[i].full = 0;
        i++;
    }
    if (pthread_mutex_init(&data->lock_1, NULL) != 0)
    {
        end_sim(data, "philo: Failed to init mutex", 1);
        return (0);
    }
    return (1);
}

int init_data(int ac, t_data *data, char **av)
{
    data->nbr_of_philo = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->eat_times = 0;
    if (ac == 6)
        data->eat_times = ft_atoi(av[5]);
    data->dead = 0;
    data->all_full = 0;
    data->time_init = 0;
    data->ph = malloc(sizeof(t_philo) * data->nbr_of_philo);
    if (!data->ph)
    {
        end_sim(data, "philo: allocation failed!", 0);
        return (0);
    }
    if (gettimeofday(&data->time, NULL) != 0)
    {
        end_sim(data, "philo: Failed to get time of day!", 1);
        return (0);
    }
    data->time_init = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
    return (1);
}

int begin_sim(int ac, t_data *data, char **av)
{
    if (init_data(ac, data, av) == 0)
        return (0);
    
    if (init_mutex(data) == 0)
        return (0);

    if (laod_philosophers(data) == 0)
        return (0);
    return (1);
}