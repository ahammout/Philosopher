/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:52:03 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/12 17:02:53 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	laod_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_of_philo)
	{
		if (pthread_create(&data->ph[i].t_id, NULL,
				dining_room, &data->ph[i]) != 0)
		{
			end_sim(data, "philo: Failed to create a thread!", 2);
			return (0);
		}
		if (pthread_detach(data->ph[i].t_id) != 0)
		{
			end_sim(data, "philo: failed to detach a thread", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_philosophers(t_data *data)
{
	int	i;
	int	next;

	i = 0;
	pthread_mutex_init(&data->print_lock, NULL);
	while (i < data->nbr_of_philo)
	{
		pthread_mutex_init(&data->ph[i].left_fork, NULL);
		if (data->nbr_of_philo > 1)
		{
			next = (i + 1) % data->nbr_of_philo;
			data->ph[i].right_fork = &data->ph[next].left_fork;
		}
		data->ph[i].id = i + 1;
		data->ph[i].data = data;
		data->ph[i].meals = 0;
		data->ph[i].last_meal = 0;
		data->ph[i].full = 0;
		i++;
	}
	return (1);
}

int	check_data(t_data *data)
{
	if (data->nbr_of_philo > 200)
	{
		printf("philo: Usage ===> [number_of_philsophers] under 200.\n");
		return (1);
	}
	if (data->time_to_die < 60)
	{
		printf("philo: Usage ===> [time_to_die] more than 60ms.\n");
		return (1);
	}
	if (data->time_to_eat < 60)
	{
		printf("philo: Usage ===> [time_to_eat] more than 60ms.\n");
		return (1);
	}
	if (data->time_to_sleep < 60)
	{
		printf("philo: Usage ===> [time_to_sleep] more than 60ms.\n");
		return (1);
	}
	return (0);
}

int	init_data(int ac, t_data *data, char **av)
{
	data->nbr_of_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->eat_times = 0;
	if (ac == 6)
		data->eat_times = ft_atoi(av[5]);
	if (check_data(data) || data->nbr_of_philo == 0)
		return (0);
	data->dead = 0;
	data->all_full = 0;
	data->ph = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->ph)
	{
		end_sim(data, "philo: allocation failed!", 0);
		return (0);
	}
	gettimeofday(&data->time, NULL);
	data->time_init = (data->time.tv_sec * 1000) + (data->time.tv_usec / 1000);
	return (1);
}

int	begin_sim(int ac, t_data *data, char **av)
{
	if (init_data(ac, data, av) == 0)
		return (0);
	if (init_philosophers(data) == 0)
		return (0);
	if (laod_philosophers(data) == 0)
		return (0);
	return (1);
}
