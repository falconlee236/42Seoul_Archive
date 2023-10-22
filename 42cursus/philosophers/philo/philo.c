/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:44:11 by sangylee          #+#    #+#             */
/*   Updated: 2023/10/11 15:36:11 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *f)
{
	int			i;
	int			flag;
	long long	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			flag = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
		if (res >= 2147483647 || res < -2147483648)
		{
			*f = 1;
			return (0);
		}
	}
	return (res * flag);
}

int	ft_mutex_init(t_data *data)
{
	int	cnt;

	cnt = 0;
	while (cnt < data->philo_num)
	{
		if (pthread_mutex_init(&data->forks[cnt++], 0) != 0)
		{
			free(data->forks);
			return (0);
		}
	}
	if ((pthread_mutex_init(&data->m_mutex, 0) != 0)
		|| (pthread_mutex_init(&data->eat_mutex, 0) != 0)
		|| (pthread_mutex_init(&data->eat_cnt_mutex, 0) != 0))
	{
		free(data->forks);
		return (0);
	}
	return (1);
}

int	case_one(t_data *data)
{
	printf("\033[0;3%dm%d %d %s\n\033[0m", 1, 0, 1, "has taken a fork");
	usleep_interval(data->die_time);
	printf("\033[0;3%dm%d %d %s\n\033[0m", 1, data->die_time, 1, "is die");
	return (0);
}

int	philo_init(t_data *data, int ac, char **av)
{
	int	flag;

	flag = 0;
	data->philo_num = ft_atoi(av[1], &flag);
	data->die_time = ft_atoi(av[2], &flag);
	data->eat_time = ft_atoi(av[3], &flag);
	data->sleep_time = ft_atoi(av[4], &flag);
	if (data->die_time <= 0 || data->eat_time <= 0 || data->sleep_time <= 0)
		return (0);
	data->must_eat = -1;
	data->monitor = 0;
	data->total_eat_cnt = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5], &flag);
	if ((data->must_eat <= 0 && ac == 6) || flag)
		return (0);
	if (data->philo_num == 1)
		return (case_one(data));
	data->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * data->philo_num);
	if (!data->forks || !ft_mutex_init(data))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;
	int		i;

	if (ac < 5 || ac > 6 || !philo_init(&data, ac, av))
		return (0);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.philo_num);
	if (!philos)
	{
		free(data.forks);
		return (0);
	}
	run_philo(&data, philos);
	i = -1;
	while (++i < data.philo_num)
		pthread_mutex_destroy(&data.forks[i]);
	free(data.forks);
	free(philos);
}
