/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/08/30 11:10:39 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	t_philo			*philo;
	struct timeval	tv;
	double			a;
	double			b;

	philo = (t_philo *)arg;
	gettimeofday(&tv, 0);
	a = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_lock(&philo->data.forks[philo->left]);
	pthread_mutex_lock(&philo->data.forks[philo->right]);
	printf("\033[0;3%dmfirst %d thread!!\n\033[0m", philo->id % 8, philo->id);
	usleep(2000000);
	printf("\033[0;3%dmsecond %d thread!!\n\033[0m", philo->id % 8, philo->id);
	gettimeofday(&tv, 0);
	b = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	printf("total time %d = %lf\n", philo->id, (b - a) / 1000);
	pthread_mutex_unlock(&philo->data.forks[philo->right]);
	pthread_mutex_unlock(&philo->data.forks[philo->left]);
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
