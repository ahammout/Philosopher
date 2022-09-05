/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:37:53 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/05 18:11:26 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int init_data(int ac, t_data *data, char **av)
{
    data->nbr_of_philo = ft_atoi(av[1]);
    if (data->nbr_of_philo == 0)
    {
        printf("philo: invalid number of philosophers");
        return (1);
    }
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
        data->eat_times = ft_atoi(av[5]);
    else
        data->eat_times = 0;
    data->ph = malloc(sizeof(t_philo) * data->nbr_of_philo);
    if (gettimeofday(&data->time, NULL) == - 1)
        return (1);
    data->time_init = data->time.tv_sec*1000 + data->time.tv_usec/1000;
    printf("Initialized time: %ld\n", data->time_init);
    return (0);
}

int begin_sim(int ac, t_data *data, char **av)
{
    int i;
    if (init_data(ac, data, av))
        return (1);
    i = 0;
    while (i < data->nbr_of_philo)
    {
        pthread_mutex_init(&data->ph[i].left_fork, NULL);
        data->ph[i].right_fork = &data->ph[(i + 1) % data->nbr_of_philo].left_fork;
        data->ph[i].id = i;
        data->ph[i].data = data;
        i++;
    }
    i = 0;
    while (i < data->nbr_of_philo)
    {
        pthread_create(&data->ph[i].id_t, NULL, philosophers, &data->ph[i]);
        i++;
    }
    i = 0;
    while (i < data->nbr_of_philo)
    {
        pthread_join(data->ph[i].id_t, NULL);
        i++;
    }
    printf("Until now ok");
    return (0);
}