/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:34:41 by ahammout          #+#    #+#             */
/*   Updated: 2022/08/27 19:11:56 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int check_args(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac < 5 || ac > 6)
    {
        printf("Usage ===> [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]");
        return(1);
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9') || (av[i][0] == '-'))
            {
                printf("Arguments must counatin only positive digits !\n");
                return(1);
            }
            j++;
        }
        i++;
    }
    return(0);
}

int main(int ac, char **av)
{
    t_data  data;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
    if (check_args(ac, av))
        return (0);
    if (init(&data, ac, av))
        return (0);
    if (init_mutex_threads(&data))
        return (0);
    return(0);
}