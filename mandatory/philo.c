/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:05:45 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/09 19:24:58 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

/*    ////////// OLDEST THINKING AREA //////////////////
    if (philo->id_n == 0 && philo->data->nbr_of_philo > 1)
    {
        pthread_mutex_lock(philo->right_fork);
        ft_print(philo, "has taken the right fork");
    } 
    pthread_mutex_lock(&philo->left_fork);
    ft_print(philo, "has taken the left fork");
    if (philo->id_n != 0)
    {
        pthread_mutex_lock(philo->right_fork);
        ft_print(philo, "has taken the right fork");
    }
*/

void	ft_print(t_philo *philo, char *status)
{	
	pthread_mutex_lock(&philo->data->lock_1);
	printf("%ldms	%d %s\n", get_time(philo->data), philo->id, status);
	if (philo->data->dead == 0 || philo->data->all_full == 0)
		pthread_mutex_unlock(&philo->data->lock_1);
}

void    thinking(t_philo *philo)
{
    ft_print(philo, "is thinking");
    if (philo->id % 2 == 0)
        usleep(50);
    pthread_mutex_lock(&philo->left_fork);
    ft_print(philo, "has taken the left fork");
    if (philo->data->nbr_of_philo == 1)
    {
        philo->data->dead = 1;
        ft_usleep(2, get_time(philo->data), philo->data);
    }
    pthread_mutex_lock(philo->right_fork);
    ft_print(philo, "has taken the right fork");
}

void    eating(t_philo *philo)
{
    ft_print(philo, "is eating");
    philo->meals++;
    philo->last_meal = get_time(philo->data);
    ft_usleep(philo->data->time_to_eat, get_time(philo->data), philo->data);
    pthread_mutex_unlock(philo->right_fork);
    pthread_mutex_unlock(&philo->left_fork);
}

void    sleeping(t_philo *philo)
{
    ft_print(philo, "is sleeping");
    ft_usleep(philo->data->time_to_sleep, get_time(philo->data), philo->data);
}

void    *dining_room(void *ptr)
{
    t_philo *philo;

    philo = ptr;
    while (philo->data->all_full != 1 && philo->data->dead != 1)
    {

        //////// THINKING AREA //////////
        thinking (philo);

        /////// EATING AREA ////////////
        eating (philo);

        ////// SLEEPING AREA ///////////
        sleeping(philo);
    }
    return (0);
}