/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:34:41 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/09 19:30:13 by ahammout         ###   ########.fr       */
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
        printf("philo: Usage ===> [number_of_philosophers]");
        printf("[time_to_die] [time_to_eat] [time_to_sleep]");
        printf(" [number_of_times_each_philosopher_must_eat]");
        return(0);
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9') || (av[i][0] == '-'))
            {
                printf("philo: Arguments must counatin only positive digits !\n");
                return(0);
            }
            j++;
        }
        i++;
    }
    return(1);
}

int main(int ac, char **av)
{
    t_data  data;
    
    /////////// CHECK ARGUMENTS ///////////////                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
    if (check_args(ac, av) == 0)
        return (0);
    
    //////////  BEGIN SIMILATION //////////////
    if (begin_sim(ac ,&data, av) == 0)
        return (0);

    ///////// WAIING END SIMILATION ////////////
    while (1)
    {
        check_status(&data);
        if (data.dead == 1 || data.all_full == 1)
        {
            ft_usleep(2, get_time(&data), &data);
            end_sim(&data, NULL, 3);
            break;
        }
    }
    return (0);
}