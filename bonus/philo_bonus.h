/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <ahammout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:13:39 by ahammout          #+#    #+#             */
/*   Updated: 2022/09/23 18:01:25 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

typedef struct s_philo
{
    struct s_data *data;
    
}               t_data;

typedef struct s_data
{
    t_philo *ph;
    int             nbr_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             eat_times;

}               t_data;
#endif