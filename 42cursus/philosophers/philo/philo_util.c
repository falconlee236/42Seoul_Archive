/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:37 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/21 15:58:34 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	tv;
	long long		tv_res;

	gettimeofday(&tv, 0);
	tv_res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tv_res);
}

void	check_die(t_data *data, t_philo *philos)
{
	int	i;
	int	flag;

	flag = 0;
	while (!flag)
	{
		i = -1;
		while (++i < data->philo_num)
		{
			pthread_mutex_lock(&data->eat_mutex);
			if (ft_get_time() - philos[i].last_time >= data->die_time)
			{
				ft_print_format(&philos[i], "died", -1);
				pthread_mutex_lock(&data->m_mutex);
				data->monitor = 1;
				flag = 1;
				pthread_mutex_unlock(&data->m_mutex);
				pthread_mutex_unlock(&data->eat_mutex);
				break ;
			}
			pthread_mutex_unlock(&data->eat_mutex);
		}
	}
}

void	usleep_interval(long long t)
{
	long long	target_time;

	target_time = t + ft_get_time();
	while (target_time > ft_get_time())
		usleep(100);
}

void	ft_print_format(t_philo *philo, char *format, int fork)
{
	long long	timestamp;

	timestamp = ft_get_time() - philo->init_time;
	pthread_mutex_lock(&philo->data->m_mutex);
	if (philo->data->monitor)
	{
		pthread_mutex_unlock(&philo->data->m_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->data->m_mutex);
	printf("\033[0;3%dm%lld %d %s %d\n\033[0m",
		philo->id % 8, timestamp, philo->id, format, fork);
	// fork = 0;
	// printf("\033[0;3%dm%lld %d %s\n\033[0m",
	// 	philo->id % 8, timestamp, philo->id, format);
}
