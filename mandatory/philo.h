/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:52 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/06 18:26:15 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/time.h>

typedef struct s_philo
{
    pthread_t       id_t;
    pthread_mutex_t left_fork;
    pthread_mutex_t *right_fork;
    long            last_meal;
    int             meals;
    int             id_n;
    struct s_data   *data;

}t_philo;

typedef struct s_data
{
    t_philo     *ph;
    pthread_t   eat_t;
    pthread_t   dead;
    long        time_init;
    struct  timeval time;
    int     nbr_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eat_times;
    
}t_data;

int     exit_error(char *error);
long    ft_atoi(char *str);
int     check_args(int ac, char **av);
int     begin_sim(int ac, t_data *data, char **av);
void    *philosophers(void *ptr);
void    *check_eat_times(void *ptr);

#endif