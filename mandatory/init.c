/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:03:19 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/27 19:10:29 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int init_mutex_threads(t_data *data)
{
    int i;

    i = 0;
    data->ph.th = malloc(sizeof(pthread_t) * data->nbr_of_philo);
    data->ph.mutex = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
    while (i < data->nbr_of_philo)
    {
        if (pthread_mutex_init(&data->ph.mutex[i], NULL) != 0)
            return (0);
        i++;
    }
    while (i < data->nbr_of_philo)
    {
        
        if (pthread_create(&data->ph.th[i], NULL, &spaghetti, data) != 0)
            return (0);
        i++;
    }
    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_join(data->ph.th[i], NULL) != 0)
            return (0);
        i++;
    }
    printf("Number of threads created: %d\n", data->nbr_of_philo);
    i = 0;
    while (i < data->nbr_of_philo)
    {
        if (pthread_mutex_destroy(&data->ph.mutex[i]) != 0)
            return (0);
        i++;
    }
    return (1);
}

int    init(t_data *data, int ac, char **av)
{
    data->nbr_of_philo = ft_atoi(av[1]);
    if (data->nbr_of_philo == 0)
    {
        printf("philo: the pogram must contain more than 0 philosophers");
        return (1);
    }
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->eat_times = ft_atoi(av[5]);
    init_mutex_threads(data);
    return(0);
}