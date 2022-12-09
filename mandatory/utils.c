/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:39:15 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/09 18:56:40 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	end_sim(t_data *data, char *error, int option)
{
	int i;

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
        ;
    }
}

long get_time(t_data *data)
{
    long ms_time;

    ms_time = 0;
    if (gettimeofday(&data->time, NULL) == -1)
	{
		end_sim(data, "philo: Failed to get time of day!", 2);
        return (0);
	}
    ms_time = (data->time.tv_sec*1000 + data->time.tv_usec/1000) - data->time_init;
    return (ms_time);
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