/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:52 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/09 17:10:20 by ahammout         ###   ########.fr       */
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
    pthread_t       t_id;
    pthread_mutex_t left_fork;
    pthread_mutex_t *right_fork;
    long            last_meal;
    int             meals;
    int             full;
    int             id;
    struct s_data   *data;

}t_philo;

typedef struct s_data
{
    t_philo         *ph;
    pthread_t       eat_t;
    pthread_t       dead_t;
    pthread_mutex_t lock_1;
    long            time_init;
    struct          timeval time;
    int             nbr_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             eat_times;
    int             all_full;
    int             dead;
    int             time_diff;
    
}t_data;

long    ft_atoi(char *str);
int     check_args(int ac, char **av);
int     begin_sim(int ac, t_data *data, char **av);
void    *dining_room(void *ptr);
void	ft_usleep(unsigned long time, unsigned long start, t_data *data);
long    get_time(t_data *data);
void	ft_print(t_philo *philo, char *status);
void    check_status(t_data *data);
int     end_sim(t_data *data, char *error, int option);
#endif