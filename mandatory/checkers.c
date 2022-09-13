/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:12:43 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/13 18:27:57 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void    *check_eat_times(void *ptr)
{
    t_data  *data;
    int     i;
    int     eat;
    
    data = ptr;
    data->full = 0;
    eat = 0;
        
    i = 0;
    while (1)
    {
        if (data->eat_times == 0)
        {
            data->full = 1;
            break;
        }
        while (i < data->nbr_of_philo)
        {
            if (data->ph[i].meals >= data->eat_times)
                eat++;
            i++;
        }
        if (eat == data->nbr_of_philo && i == data->nbr_of_philo)
        {
            //ft_print(data->ph, "Finish Eating", 1);
            data->full = 1;
            break;
        }
        i = 0;
        eat = 0;
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
            if (time > (data->ph[i].last_meal + data->time_to_die))
            {
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