/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:44:11 by sangylee          #+#    #+#             */
/*   Updated: 2023/09/12 17:15:24 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoll(char *str)
{
	int			i;
	int			flag;
	long long	res;

	i = 0;
	res = 0;
	flag = 1;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		res = (res * 10LL) + (str[i++] - '0');
	return (res * flag);
}

int	ft_mutex_init(t_data *data)
{
	int	cnt;

	cnt = data->philo_num;
	while (--cnt)
	{
		if (pthread_mutex_init(&data->forks[cnt], 0) != 0)
		{
			free(data->forks);
			return (0);
		}
	}
	pthread_mutex_init(&data->m_mutex, 0);
	return (1);
}

int	philo_init(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoll(av[1]);
	data->die_time = ft_atoll(av[2]);
	data->eat_time = ft_atoll(av[3]);
	data->sleep_time = ft_atoll(av[4]);
	data->must_eat = 0;
	data->monitor = 0;
	if (ac == 6)
		data->must_eat = ft_atoll(av[5]);
	data->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->forks || !ft_mutex_init(data))
		return (0);
	return (1);
}

void	leak_check(void)
{
	system("leaks philo");
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	atexit(leak_check);
	if (ac < 5 || ac > 6 || !philo_init(&data, ac, av))
		return (0);
	philos = (t_philo *)malloc(sizeof(t_philo) * (data.philo_num + 1));
	if (!philos)
	{
		free(data.forks);
		return (0);
	}
	if (!run_philo(&data, philos))
	{
		free(data.forks);
		free(philos);
	}
}
