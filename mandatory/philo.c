/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/15 15:45:10 by ahammout         ###   ########.fr       */
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
    pthread_mutex_destroy(&data->lock_1);
    pthread_mutex_destroy(&data->lock_2);
    //free(data->ph);
}

void    *philosophers(void *ptr)
{
    t_philo  *philo;

    philo = ptr;
    while(1)
    {
        if (philo->data->dead == 1)
        {
            end_sim(philo->data);
            break;
        }
        if (philo->data->full == 1)
        {
            end_sim(philo->data);
            break;
        }
        if (philo->id_n == 0)
        {
            ft_print(philo, "has taken the right fork", 0);
            pthread_mutex_lock(philo->right_fork);
        }
        ft_print(philo, "has taken the left fork", 0);
        pthread_mutex_lock(&philo->left_fork);
        if (philo->id_n != 0)
        {
            ft_print(philo, "has taken the right fork", 0);
            pthread_mutex_lock(philo->right_fork);
        }
        ft_print(philo, "is eating", 0);
        philo->last_meal = get_time(philo->data);
        usleep(philo->data->time_to_eat * 1000);
        philo->meals++;
        ft_print(philo, "has put the right fork", 0);
        pthread_mutex_unlock(philo->right_fork);
        ft_print(philo, "has put the left fork", 0);
        pthread_mutex_unlock(&philo->left_fork);
        ft_print(philo, "is sleeping", 0);
        usleep(philo->data->time_to_sleep * 1000);
        ft_print(philo, "is thinking", 0);
    }
    return (0);
}