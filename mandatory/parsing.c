#include"philo.h"

int check_args(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac < 5 || ac > 6)
    {
        exit_error("Usage ===> [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]");
        return(0);
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!(av[i][j] >= '0' && av[i][j] <= '9'))
                exit_error("Arguments must counatin only digits !\n");
            j++;
        }
        i++;
    }
    return(1);
}

void    parsing(t_philo *philo, int ac, char **av)
{
    if (check_args(ac, av) == 1)
    {
        philo->philo_num = ft_atoi(av[1]);
        philo->time_to_die = ft_atoi(av[2]);
        philo->time_to_eat = ft_atoi(av[3]);
        philo->time_to_sleep = ft_atoi(av[4]);
        if (ac == 6)
            philo->eat_times = ft_atoi(av[5]);
    }
}