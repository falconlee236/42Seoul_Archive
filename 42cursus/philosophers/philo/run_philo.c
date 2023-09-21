/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/21 16:00:50 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep_interval(5);
	while (1)
	{
		pthread_mutex_lock(&philo->data->m_mutex);
		if (philo->data->monitor)
		{
			pthread_mutex_unlock(&philo->data->m_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->m_mutex);
		pthread_mutex_lock(&philo->data->forks[philo->left]);
		ft_print_format(philo, "has taken a fork", philo->left);
		if (philo->data->philo_num != 1)
		{
			pthread_mutex_lock(&philo->data->forks[philo->right]);
			ft_print_format(philo, "has taken a fork", philo->right);
			ft_print_format(philo, "is eating", -1);
			pthread_mutex_lock(&philo->data->eat_mutex);
			philo->last_time = ft_get_time();
			pthread_mutex_unlock(&philo->data->eat_mutex);
			usleep_interval(philo->data->eat_time);
			ft_print_format(philo, "is sleeping", -1);
			pthread_mutex_unlock(&philo->data->forks[philo->right]);
		}
		pthread_mutex_unlock(&philo->data->forks[philo->left]);
		usleep_interval(philo->data->sleep_time);
		ft_print_format(philo, "is thinking", -1);
	}
	return (arg);
}

int	ft_philo_init(t_philo *philo, int id)
{
	philo->id = id + 1;
	philo->left = id;
	philo->right = (id + 1) % philo->data->philo_num;
	philo->eat_cnt = 0;
	if (pthread_create(&philo->thread, 0, ft_thread, philo) != 0)
		return (0);
	return (1);
}

int	run_philo(t_data *data, t_philo *philos)
{
	int			i;
	long long	init_time;

	i = -1;
	init_time = ft_get_time();
	while (++i < data->philo_num)
	{
		philos[i].data = data;
		philos[i].init_time = init_time;
		philos[i].last_time = init_time;
		if (!ft_philo_init(&philos[i], i))
			return (0);
	}
	check_die(data, philos);
	i = -1;
	while (++i < data->philo_num)
		pthread_join(philos[i].thread, 0);
	return (1);
}
