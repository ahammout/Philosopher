/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/19 17:22:21 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_usleep(unsigned long time, unsigned long start, t_data *data)
{
	usleep(time * 1000 * 0.95);
	while (get_time(data) - start < time)
		usleep(50);
}

void    end_sim(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nbr_of_philo)
    {
        pthread_mutex_destroy(&data->ph[i].left_fork);
        i++;
    }
    pthread_mutex_destroy(&data->lock_1);
    free(data->ph);
}

void    *philosophers(void *ptr)
{
    t_philo  *philo;

    philo = ptr;
    while(1)
    {
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
        ft_usleep(philo->data->time_to_eat, get_time(philo->data), philo->data);
        philo->meals++;
        // ft_print(philo, "has put the right fork", 0);
        pthread_mutex_unlock(philo->right_fork);
        // ft_print(philo, "has put the left fork", 0);
        pthread_mutex_unlock(&philo->left_fork);
        ft_print(philo, "is sleeping", 0);
        ft_usleep(philo->data->time_to_sleep, get_time(philo->data), philo->data);
        ft_print(philo, "is thinking", 0);
    }
    return (0);
}