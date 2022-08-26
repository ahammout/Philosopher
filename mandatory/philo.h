/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:52 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/26 15:02:51 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct s_philo
{
    pthread_t   *th;
    pthread_mutex_t mutex;
    int     philo_num;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eat_times;
    
}t_philo;

int     exit_error(char *error);
long    ft_atoi(char *str);
void    parsing(t_philo *philo, int ac, char **av);
void    create_threads(t_philo *philo);


#endif