/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/06 12:57:25 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

double	ft_get_time(void)
{
	struct timeval	tv;
	double			tv_res;

	gettimeofday(&tv, 0);
	tv_res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tv_res);
}

void	usleep_interval(long long t)
{
	long long	res;

	res = 0;
	while (res <= t)
	{
		usleep(100);
		res += 100ll;
	}
}

void	*ft_thread(void *arg)
{
	t_philo			*philo;
	double			b;
	int				i;

	philo = (t_philo *)arg;
	i = 0;
	philo->init_time = ft_get_time();
	while (i < 10)
	{
		pthread_mutex_lock(&philo->data.forks[philo->left]);
		pthread_mutex_lock(&philo->data.forks[philo->right]);
		printf("\033[0;3%dm %d has taken a fork - %d\n\033[0m",
			philo->id % 8, philo->id, i);
		printf("\033[0;3%dm %d has taken a fork - %d\n\033[0m",
			philo->id % 8, philo->id, i);
		usleep(philo->data.eat_time * 1000);
		b = ft_get_time();
		printf("total time %d = %lf\n",
			philo->id, (b - philo->init_time) / 1000);
		pthread_mutex_unlock(&philo->data.forks[philo->right]);
		pthread_mutex_unlock(&philo->data.forks[philo->left]);
		i++;
	}
	return (arg);
}

int	ft_philo_init(t_philo *philo, int id)
{
	philo->id = id;
	philo->left = id;
	philo->right = (id + 1) % philo->data.philo_num;
	philo->eat_cnt = 0;
	if (pthread_create(&philo->thread, 0, ft_thread, philo) != 0)
		return (0);
	return (1);
}

int	run_philo(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		philos[i].data = *data;
		if (!ft_philo_init(&philos[i], i))
			return (0);
	}
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philos[i].thread, 0);
	return (1);
}
