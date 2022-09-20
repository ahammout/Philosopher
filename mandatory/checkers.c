/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:12:43 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/20 19:10:37 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    *check_eat_times(void *ptr)
{
    t_data  *data;
    int     i;
    int     is_full;
    
    data = ptr;
    data->full = 0;
    is_full = 0;
        
    i = 0;
    while (1)
    {
        if (data->eat_times <= 0 || data->dead == 1)
        {
            data->full = 1;
            return (0);
        }
        while (i < data->nbr_of_philo)
        {
            if (data->ph[i].meals == data->eat_times)
                is_full++;
            if (is_full == data->nbr_of_philo)
            {
                data->full = 1;
                return (0);
            }
            i++;
        }
        i = 0;
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
            if (time > (data->ph[i].last_meal + data->time_to_die)
                || (data->full == 1) || data->nbr_of_philo == 1)
            {
                if (data->full != 1)
                    ft_print(&data->ph[i], "dead", 1);
                data->dead = 1;
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