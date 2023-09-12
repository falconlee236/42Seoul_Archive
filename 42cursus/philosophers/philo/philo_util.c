/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:03:37 by isang-yun         #+#    #+#             */
/*   Updated: 2023/09/12 14:17:58 by isang-yun        ###   ########.fr       */
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

int	check_die(t_philo *philo)
{
	if (philo->last_time - philo->init_time >= philo->data.die_time)
		return (
                printf("%lld %d is died\n", philo->last_time - ft_get_time(), philo->id)
        );
	return (0);
}

void	usleep_interval(long long t)
{
	long long	target_time;

	target_time = t + (long long)ft_get_time();
	while (target_time > (long long)ft_get_time())
		usleep(100);
}
