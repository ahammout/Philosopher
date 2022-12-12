/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:47:16 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/12 17:00:26 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	all_is_full(t_data *data)
{
	int	i;
	int	all_full;

	i = 0;
	all_full = 0;
	while (i < data->nbr_of_philo)
	{
		if (data->ph[i].full == 1)
			all_full++;
		i++;
	}
	if (all_full == data->nbr_of_philo)
		return (1);
	return (0);
}

void	check_status(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		if (data->eat_times > 0)
		{
			if (data->ph[i].meals >= data->eat_times)
				data->ph[i].full = 1;
			if (all_is_full(data))
			{
				data->all_full = 1;
				break ;
			}
		}
		if ((get_time(data) - data->ph[i].last_meal) > data->time_to_die)
		{
			data->dead = 1;
			//////// SLEEP A WHILE TO LET OTHER THREADS FINISH THIER EXEC /////// 
			ft_usleep(1, get_time(data), data);
			printf("%ldms	%d died\n", get_time(data), data->ph[i].id);
			break ;
		}
		i++;
	}
}
