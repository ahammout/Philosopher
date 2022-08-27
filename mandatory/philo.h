/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:52 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/27 19:08:31 by ahammout         ###   ########.fr       */
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
    pthread_t       *th;
    pthread_mutex_t *mutex;

}t_philo;

typedef struct s_data
{
    t_philo ph;
    int     nbr_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     eat_times;
    
}t_data;

int     exit_error(char *error);
long    ft_atoi(char *str);
int     check_args(int ac, char **av);
int     init(t_data *data, int ac, char **av);
int     init_mutex_threads(t_data *data);
void    *spaghetti(void *ptr);


#endif