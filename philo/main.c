/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 12:56:21 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/12 18:09:01 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_args(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("philo: Usage ===> [number_of_philosophers]");
		printf("[time_to_die] [time_to_eat] [time_to_sleep]");
		printf(" [number_of_times_each_philosopher_must_eat]");
		return (0);
	}
	if (is_ipositive(av) == 0)
	{
		printf("philo: Arguments needs to be povitive integers.\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (check_args(ac, av) == 0)
		return (0);
	if (begin_sim(ac, &data, av) == 0)
		return (0);
	while (1)
	{
		check_status(&data);
		if (data.dead == 1 || data.all_full == 1)
		{
			ft_usleep(2, get_time(&data), &data);
			end_sim(&data, NULL, 3);
			break ;
		}
	}
	return (0);
}
