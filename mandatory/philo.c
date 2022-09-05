/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/05 18:28:36 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"



long get_time(t_data *data)
{
    long ms_time;

    ms_time = 0;
    if (gettimeofday(&data->time, NULL) == -1)
        return (0);
    ms_time = data->time.tv_sec*1000 + data->time.tv_usec/1000 - data->time_init;
    return (ms_time);
}

void    *philosophers(void *ptr)
{
    t_philo  *philo;
    int i;

    philo = ptr;
    i = -1;
    while(i < philo->data->eat_times)
    {
        check_status(philo);
        if (philo->id == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            printf("[%ld] %d has taken the right fork\n", get_time(philo->data), philo->id + 1);
        }
        pthread_mutex_lock(&philo->left_fork);
        printf("[%ld] %d has taken the left fork\n", get_time(philo->data), philo->id + 1);
        if (philo->id != 0)
        {
            pthread_mutex_lock(philo->right_fork);
            printf("[%ld] %d has taken the right fork\n", get_time(philo->data), philo->id + 1);
        }
        printf("[%ld] %d is eating\n", get_time(philo->data), philo->id + 1);
        usleep(philo->data->time_to_eat * 1000);
        philo->last_mile = get_time(philo->data);
        pthread_mutex_unlock(philo->right_fork);
        printf("[%ld] %d has put the right fork\n", get_time(philo->data), philo->id + 1);
        pthread_mutex_unlock(&philo->left_fork);
        printf("[%ld] %d has put the left fork\n", get_time(philo->data), philo->id + 1);
        printf("[%ld] %d is sleeping\n", get_time(philo->data), philo->id + 1);
        usleep(philo->data->time_to_sleep * 1000);
        printf("[%ld] %d is thinking\n", get_time(philo->data), philo->id + 1);
    }
    return NULL;
}