/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 18:39:15 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/10 18:39:18 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long get_time(t_data *data)
{
    long ms_time;

    ms_time = 0;
    if (gettimeofday(&data->time, NULL) == -1)
        return (0);
    ms_time = (data->time.tv_sec*1000 + data->time.tv_usec/1000) - data->time_init;
    return (ms_time);
}

void	ft_print(t_philo *philo, char *status, int action)
{
	pthread_mutex_lock(&philo->data->lock);
	printf("[%ld] %d %s\n", get_time(philo->data), philo->id_n + 1, status);
	if (action == 0)
		pthread_mutex_unlock(&philo->data->lock);
	// if (philo->data->philo_full == philo->data->nbr_of_philo)
	// 	printf("all philos %d finish eating\n", philo->data->philo_full);
}

int	exit_error(t_data *data, char *error, int option)
{
	int i;

	i = 0;
	if (option == 0)
	{
    	printf("%s\n", error);
		return (1);
	}
	if (option == 1)
	{
		free(data->ph);
		printf("%s\n", error);
	}
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