/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:39:15 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/19 19:11:47 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long get_time(t_data *data)
{
    long ms_time;

    ms_time = 0;
    if (gettimeofday(&data->time, NULL) == -1)
	{
		exit_error(data, "philo: Failed to get time of day!", 2);
        return (0);
	}
    ms_time = (data->time.tv_sec*1000 + data->time.tv_usec/1000) - data->time_init;
    return (ms_time);
}

void	ft_print(t_philo *philo, char *status, int action)
{	
	pthread_mutex_lock(&philo->data->lock_1);
	if (!action)
		printf("[%ld] %d %s\n", get_time(philo->data), philo->id_n + 1, status);
	if (!action)
		pthread_mutex_unlock(&philo->data->lock_1);
	if (action)
		printf("thats it");
}

int	exit_error(t_data *data, char *error, int option)
{
	int i;

	i = 0;
	if (option == 1)
		free(data->ph);
	if (option == 2)
	{
		while (i < data->nbr_of_philo)
		{
			pthread_mutex_destroy(&data->ph[i].left_fork);
			i++;
		}
		pthread_mutex_destroy(&data->lock_1);
		free(data->ph);
	}
	printf("%s\n", error);
	return (0);
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