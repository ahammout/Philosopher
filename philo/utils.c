/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:32:39 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/11 21:30:20 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	end_sim(t_data *data, char *error, int option)
{
	int	i;

	i = 0;
	if (option == 1)
		free(data->ph);
	if (option == 2 || option == 3)
	{
		while (i < data->nbr_of_philo)
		{
			pthread_mutex_destroy(&data->ph[i].left_fork);
			i++;
		}
		free(data->ph);
	}
	if (option == 2 || option == 1)
		printf("%s\n", error);
	return (0);
}

void	ft_usleep(unsigned long time, unsigned long start, t_data *data)
{
	usleep(time * 1000 * 0.95);
	while (get_time(data) - start < time)
	{
	}
}

long	get_time(t_data *data)
{
	long	ms_time;

	ms_time = 0;
	gettimeofday(&data->time, NULL);
	ms_time = (data->time.tv_sec * 1000 + data->time.tv_usec / 1000);
	ms_time -= data->time_init;
	return (ms_time);
}

int	is_ipositive(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ' || av[i][j] == '\t')
			j++;
		if (av[i][j] == '-')
			return (0);
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str ++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * sign);
}
