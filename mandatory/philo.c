/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/26 15:40:40 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"


void    *spaghetti()
{
    pthread_mutex_lock(philo->mutex);
        printf("Executing thread\n");
        sleep(1);
        printf("finishing thread\n");
    pthread_mutex_unlock(philo->mutex);
    return (NULL);
}

void    create_threads(t_philo *philo)
{
    int i;
    pthread_mutex_init(&philo->mutex, NULL);

    i = 0;
    philo->th = malloc(sizeof(pthread_t) * philo->philo_num);
    while (i < philo->philo_num)
    {
        pthread_create(&philo->th[i], NULL, &spaghetti, NULL);
        i++;
    }
    i = 0;
    while (i < philo->philo_num)
    {
        pthread_join(philo->th[i], NULL);
        i++;
    }
    printf("Number of threads created: %d\n", philo->philo_num);
    pthread_mutex_destroy(&philo->mutex)
    
}