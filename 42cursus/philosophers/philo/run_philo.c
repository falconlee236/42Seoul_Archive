/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/12 15:21:46 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	philo->init_time = ft_get_time();
	philo->last_time = philo->init_time;
	if (philo->id % 2 == 0)
		usleep_interval(1000);
	while (!check_die(philo))
	{
		pthread_mutex_lock(&philo->data.forks[philo->left]);
		ft_print_format(philo, "has taken a fork", philo->left);
		pthread_mutex_lock(&philo->data.forks[philo->right]);
		ft_print_format(philo, "has taken a fork", philo->right);
		ft_print_format(philo, "is eating", -1);
		philo->last_time = ft_get_time();
		usleep_interval(philo->data.eat_time);
		pthread_mutex_unlock(&philo->data.forks[philo->right]);
		pthread_mutex_unlock(&philo->data.forks[philo->left]);
		ft_print_format(philo, "is sleeping", -1);
		usleep_interval(philo->data.sleep_time);
		ft_print_format(philo, "is thinking", -1);
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
