/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:37 by isang-yun         #+#    #+#             */
/*   Updated: 2023/10/14 21:31:20 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	tv;
	long long		tv_res;

	gettimeofday(&tv, 0);
	tv_res = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tv_res);
}

int	check_eat(t_data *data)
{
	sem_wait(data->eat_cnt_sem);
	if (data->total_eat_cnt == data->philo_num)
	{
		sem_wait(data->m_sem);
		data->monitor = 1;
		sem_post(data->m_sem);
		sem_post(data->eat_cnt_sem);
		return (1);
	}
	sem_post(data->eat_cnt_sem);
	return (0);
}

void	*check_die(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		sem_wait(philo->data->eat_sem);
		if (ft_get_time() - philo->last_time >= philo->data->die_time)
		{
			ft_print_format(philo, "died");
			sem_wait(philo->data->m_sem);
			philo->data->monitor = 1;
			sem_post(philo->data->m_sem);
			sem_post(philo->data->eat_sem);
			exit(1);
		}
		sem_post(philo->data->eat_sem);
		usleep(1000);
	}
}

void	usleep_interval(long long t)
{
	long long	target_time;

	target_time = t + ft_get_time();
	while (target_time > ft_get_time())
		usleep(100);
}

void	ft_print_format(t_philo *philo, char *format)
{
	long long	timestamp;

	timestamp = ft_get_time() - philo->init_time;
	sem_wait(philo->data->m_sem);
	if (philo->data->monitor)
	{
		sem_post(philo->data->m_sem);
		return ;
	}
	printf("\033[0;3%dm%lld %d %s\n\033[0m",
		philo->id % 8, timestamp, philo->id, format);
	sem_post(philo->data->m_sem);
}
