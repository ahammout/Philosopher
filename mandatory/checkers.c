/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:12:43 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/26 18:46:38 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    *check_eat_times(void *ptr)
{
    t_data  *data;
    int     i;
    int     is_full;
    
    data = ptr;
    
    i = 1;
    is_full = 0;
    while (i <= data->nbr_of_philo)
    {
        if (data->ph[i].meals == data->eat_times)
            is_full++;
        if (is_full == data->nbr_of_philo)
        {
            data->full = 1;
            return (0);
        }
        if (i == data->nbr_of_philo)
            i = 0;
        i++;
    }
    return (0);
}

void    *check_dead(void *ptr)
{
    t_data  *data;
    long    time;
    int     i;

    data = ptr;
    i = 0;
    while (1)
    {
        while (i < data->nbr_of_philo)
        {
            time = get_time(data);
          //printf("The last meal of  philo [ %d ]: %ld\n\n", data->ph[i].id_n, data->ph[i].last_meal);
            if (time > (data->ph[i].last_meal + data->time_to_die)
                || (data->full == 1) || data->nbr_of_philo == 1)
            {
                data->dead = 1;
                if (data->full != 1)
                    ft_print(&data->ph[i], "dead", 1);
                printf("The last meal of  philo [ %d ]: %ld real time: %ld\n\n", data->ph[i].id_n + 1, data->ph[i].last_meal, time);
                break;
            }
            i++;
        }
        if (data->dead == 1)
            break;
        i = 0;
    }
    return (0);
}