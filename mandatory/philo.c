/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/06 18:43:20 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    end_sim(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        pthread_mutex_destroy(data->ph[i].right_fork);
        i++;
    }
    exit(0);
}

void    *check_eat_times(void *ptr)
{
    t_data  *data;
    int     i;
    int     philo;
    
    data = ptr;
    i = 0;
    philo = 1;
    while (1)
    {
        while(i < data->nbr_of_philo)
        {
            if (data->ph[i].meals == data->eat_times)
                philo++;
            i++;
        }
        if (philo == data->nbr_of_philo)
            break;
        i = 0;
        philo = 0;
    }
    end_sim(data);
    return (0);
}

// void    *check_status(void *ptr)
// {
//     t_data  *data;

//     data = ptr;
//     while (1)
//     {
//         printf("status of dead checked successfully\n");
//         usleep(1000);
//     }
//     return (0);
// }

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
        if (philo->id_n == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            printf("[%ld] %d has taken the right fork\n", get_time(philo->data), philo->id_n + 1);
        }
        pthread_mutex_lock(&philo->left_fork);
        printf("[%ld] %d has taken the left fork\n", get_time(philo->data), philo->id_n + 1);
        if (philo->id_n != 0)
        {
            pthread_mutex_lock(philo->right_fork);
            printf("[%ld] %d has taken the right fork\n", get_time(philo->data), philo->id_n + 1);
        }
        printf("[%ld] %d is eating\n", get_time(philo->data), philo->id_n + 1);
        usleep(philo->data->time_to_eat * 1000);
        philo->last_meal = get_time(philo->data);
        philo->meals++;
        pthread_mutex_unlock(philo->right_fork);
        printf("[%ld] %d has put the right fork\n", get_time(philo->data), philo->id_n + 1);
        pthread_mutex_unlock(&philo->left_fork);
        printf("[%ld] %d has put the left fork\n", get_time(philo->data), philo->id_n + 1);
        printf("[%ld] %d is sleeping\n", get_time(philo->data), philo->id_n + 1);
        usleep(philo->data->time_to_sleep * 1000);
        printf("[%ld] %d is thinking\n", get_time(philo->data), philo->id_n + 1);
    }
    return NULL;
}