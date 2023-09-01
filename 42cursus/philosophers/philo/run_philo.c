/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/01 10:03:56 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// long long	ft_get_time()

void	*ft_thread(void *arg)
{
	t_philo			*philo;
	struct timeval	tv;
	long long		b;
	int				i;

	philo = (t_philo *)arg;
	i = 0;
	gettimeofday(&tv, 0);
	philo->init_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (i < 5)
	{
		pthread_mutex_lock(&philo->data.forks[philo->left]);
		pthread_mutex_lock(&philo->data.forks[philo->right]);
		printf("\033[0;3%dmfirst %d thread-%d\n\033[0m",
			philo->id % 8, philo->id, i);
		printf("\033[0;3%dmsecond %d thread-%d\n\033[0m",
			philo->id % 8, philo->id, i);
		usleep(philo->data.eat_time * 1000);
		gettimeofday(&tv, 0);
		b = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		printf("total time %d = %lld\n",
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
