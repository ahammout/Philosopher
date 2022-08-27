/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/27 19:13:29 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"


void    *spaghetti(void *ptr)
{
    t_data  *data;
    int     i;

    data = ptr;
    i = 0;
    printf("timestamp_in_ms X is thinking\n");
    while (i < data->nbr_of_philo)
    {
        pthread_mutex_lock(&data->ph.mutex[i]);
        printf("timestamp_in_ms X has taken a fork\n");
        printf("timestamp_in_ms X is eating\n");
        sleep(3);
        printf("timestamp_in_ms X is sleeping\n");
        pthread_mutex_unlock(&data->ph.mutex[i]);
        i++;
    }
    return (NULL);
}