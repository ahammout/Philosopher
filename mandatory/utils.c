/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:39:15 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/26 16:08:15 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_print(t_philo *philo, char *status, int action)
{	
	(void)action;
	pthread_mutex_lock(&philo->data->lock_1);
	printf("%ldms	%d %s\n", get_time(philo->data), philo->id_n + 1, status);
	if (philo->data->dead == 0 || philo->data->full == 0)
		pthread_mutex_unlock(&philo->data->lock_1);
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