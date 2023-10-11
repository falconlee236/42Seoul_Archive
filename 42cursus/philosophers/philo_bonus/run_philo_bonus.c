/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/10/11 15:54:42 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	thread_logic(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print_format(philo, "has taken a fork");
	ft_print_format(philo, "is eating");
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->data->must_eat)
	{
		sem_wait(philo->data->eat_cnt_sem);
		philo->data->total_eat_cnt++;
		sem_post(philo->data->eat_cnt_sem);
	}
	sem_wait(philo->data->eat_sem);
	philo->last_time = ft_get_time();
	sem_post(philo->data->eat_sem);
	usleep_interval(philo->data->eat_time);
	ft_print_format(philo, "is sleeping");
	sem_post(philo->data->forks);
}

void	ft_thread(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep_interval(5);
	while (1)
	{
		sem_wait(philo->data->m_sem);
		if (philo->data->monitor)
		{
			sem_post(philo->data->m_sem);
			break ;
		}
		sem_post(philo->data->m_sem);
		sem_wait(philo->data->forks);
		ft_print_format(philo, "has taken a fork");
		thread_logic(philo);
		sem_post(philo->data->forks);
		usleep_interval(philo->data->sleep_time);
		ft_print_format(philo, "is thinking");
	}
}

int	ft_philo_init(t_philo *philo, int id)
{
	philo->id = id + 1;
	philo->eat_cnt = 0;
	philo->thread = fork();
	if (philo->thread == -1)
		return (0);
	if (philo->thread == 0)
		ft_thread(philo);
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
		printf("%d %d\n", waitpid(philos[i].thread, 0, 0), philos[i].thread);
	return (1);
}
