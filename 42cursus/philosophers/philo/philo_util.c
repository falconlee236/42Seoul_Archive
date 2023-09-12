/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:37 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/12 17:22:17 by isang-yun        ###   ########.fr       */
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

void	check_die(t_philo *philo)
{
	pthread_mutex_lock(&philo->data.m_mutex);
	if (philo->last_time - philo->init_time >= philo->data.die_time)
	{
		philo->data.monitor = 1;
		ft_print_format(philo, "is died", -1);
	}
	pthread_mutex_unlock(&philo->data.m_mutex);
}

void	usleep_interval(long long t)
{
	long long	target_time;

	target_time = t + (long long)ft_get_time();
	while (target_time > (long long)ft_get_time())
		usleep(100);
}

void	ft_print_format(t_philo *philo, char *format, int fork)
{
	long long	timestamp;

	timestamp = philo->last_time - philo->init_time;
	printf("\033[0;3%dm%lld %d %s %d\n\033[0m", 
		philo->id % 8, timestamp, philo->id, format, fork);
}
