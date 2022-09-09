/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/09 19:18:36 by ahammout         ###   ########.fr       */
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
        pthread_mutex_destroy(&data->ph[i].left_fork);
        i++;
    }
    pthread_mutex_destroy(&data->lock);
    free(data->ph);
    exit(0);
}

long get_time(t_data *data)
{
    long ms_time;

    ms_time = 0;
    if (gettimeofday(&data->time, NULL) == -1)
        return (0);
    ms_time = (data->time.tv_sec*1000 + data->time.tv_usec/1000) - data->time_init;
    return (ms_time);
}

void    *check_eat_times(void *ptr)
{
    t_data  *data;
    int     i;
    
    data = ptr;
    data->full = 0;
    i = 0;
    while (1)
    {
        while (i < data->nbr_of_philo)
        {
            if (data->ph[i].meals >= data->eat_times)
                data->full++;
            i++;
        }
        if (data->full == data->nbr_of_philo && i == data->nbr_of_philo)
        {
            printf(" the philo var: %d\n", data->full);
            end_sim(data);
        }
        i = 0;
        data->full = 0;
    }
    return (0);
}

void    *check_status(void *ptr)
{
    t_data  *data;
    long    time;
    int     i;

    data = ptr;
    i = 0;
    while (1)
    {
        while (i < data->nbr_of_philo )
        {
            time = get_time(data);
            if (time > (data->ph[i].last_meal + data->time_to_die))
            {
                printf("diff /philo time : %ld, real time : %ld\n", data->ph[i].last_meal + data->time_to_die, time);
                data->dead = 1;
                ft_print(&data->ph[i], "dead", 1);
                exit(0);
            }
            i++;
        }
    }
    return (0);
}

void    *philosophers(void *ptr)
{
    t_philo  *philo;

    philo = ptr;
    while(1)
    {
        if (philo->id_n == 0)
        {
            pthread_mutex_lock(philo->right_fork);
            ft_print(philo, "has taken the right fork", 0);
        }
        pthread_mutex_lock(&philo->left_fork);
        ft_print(philo, "has taken the left fork", 0);
        if (philo->id_n != 0)
        {
            pthread_mutex_lock(philo->right_fork);
            ft_print(philo, "has taken the right fork", 0);
        }
        philo->last_meal = get_time(philo->data);
        ft_print(philo, "is eating ksekso", 0);
        usleep(philo->data->time_to_eat * 1000);
        // printf("last meal of philo nubmer: %d/ time %ld\n", philo->id_n, philo->last_meal);
        philo->meals++;
        // printf("The philo n[%d] taked the meal number %d\n\n", philo->id_n + 1, philo->meals);
        pthread_mutex_unlock(philo->right_fork);
        // ft_print(philo, "has put the right fork", 0);
        pthread_mutex_unlock(&philo->left_fork);
        // ft_print(philo, "has put the left fork", 0);
        ft_print(philo, "is sleeping", 0);
        usleep(philo->data->time_to_sleep * 1000);
        ft_print(philo, "is thinking", 0);
    }
    return NULL;
}