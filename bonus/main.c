/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:13:01 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/23 17:53:16 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int check_args(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac < 5 || ac > 6)
    {
        printf("philo: Usage ===> [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]");
        return(1);
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9') || (av[i][0] == '-'))
            {
                printf("philo: Arguments must counatin only positive digits !\n");
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
    t_dat
}