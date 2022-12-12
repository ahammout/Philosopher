/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahammout <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:30:50 by ahammout          #+#    #+#             */
/*   Updated: 2022/12/11 13:30:54 by ahammout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<pthread.h>
# include<sys/time.h>

typedef struct s_philo
{
	pthread_t		t_id;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	int				id;
	long			last_meal;
	int				meals;
	int				full;
	struct s_data	*data;

}t_philo;

typedef struct s_data
{
	t_philo			*ph;
	pthread_mutex_t	print_lock;
	struct timeval	time;
	long			time_init;
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_times;
	int				all_full;
	int				dead;
}t_data;

long	ft_atoi(char *str);
int		is_ipositive(char **av);
int		check_args(int ac, char **av);
int		begin_sim(int ac, t_data *data, char **av);
void	*dining_room(void *ptr);
void	ft_usleep(unsigned long time, unsigned long start, t_data *data);
long	get_time(t_data *data);
void	ft_print(t_philo *philo, char *status);
void	check_status(t_data *data);
int		end_sim(t_data *data, char *error, int option);
#endif
