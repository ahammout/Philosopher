/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/26 18:40:55 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_usleep(unsigned long time, unsigned long start, t_data *data)
{
	usleep(time * 1000 * 0.95);
	while (get_time(data) - start < time)
    {
        ;
    }
}

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
		pthread_mutex_destroy(&data->lock_1);
		free(data->ph);
	}
    if (option == 2 || option == 1)
	    printf("%s\n", error);
	return (0);
}

void    *philosophers(void *ptr)
{
    t_philo  *philo;

    philo = ptr;
    while(1)
    {
        if (philo->id_n == 0 && philo->data->nbr_of_philo > 1)
        {
            pthread_mutex_lock(philo->right_fork);
            ft_print(philo, "has taken the right fork", 0);
        } 
        pthread_mutex_lock(&philo->left_fork);
        ft_print(philo, "has taken the left fork", 0);
        if (philo->id_n != 0)
        {
            pthread_mutex_lock(philo->right_fork);
            ft_print(philo, "has taken the right fork", 0);
        }
        ft_print(philo, "is eating", 0);
        philo->meals++;
        philo->last_meal = get_time(philo->data);
        ft_usleep(philo->data->time_to_eat, get_time(philo->data), philo->data);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(&philo->left_fork);
        ft_print(philo, "is sleeping", 0);
        ft_usleep(philo->data->time_to_sleep, get_time(philo->data), philo->data);
        ft_print(philo, "is thinking", 0);
    }
    return (0);
}