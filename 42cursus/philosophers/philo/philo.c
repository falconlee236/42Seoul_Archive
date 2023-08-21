/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:44:11 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/21 14:24:42 by sangylee         ###   ########.fr       */
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

int	pthread_init(t_data *data)
{
	int	cnt;

	cnt = data->philo_num;
}

int	philo_init(t_data *data, int ac, char **av)
{
	data->philo_num = ft_atoll(av[1]);
	data->die_time = ft_atoll(av[2]);
	data->eat_time = ft_atoll(av[3]);
	data->sleep_time = ft_atoll(av[4]);
	if (ac == 6)
		data->must_eat = ft_atoll(av[5]);
	data->philos = (pthread_t *)malloc(
			sizeof(pthread_t) * (data->philo_num + 1));
	if (!data->philos)
		return (0);
	data->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * (data->philo_num + 1));
	if (!data->forks)
	{
		free(data->philos);
		return (0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6 || !philo_init(&data, ac, av))
		return (0);
}
