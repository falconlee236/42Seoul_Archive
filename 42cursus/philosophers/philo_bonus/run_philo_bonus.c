/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/10/12 18:29:05 by sangylee         ###   ########.fr       */
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
		// sem_post(philo->data->forks);
		// sem_post(philo->data->forks);
		// exit(0);
		// sem_wait(philo->data->eat_cnt_sem);
		// philo->data->total_eat_cnt++;
		// sem_post(philo->data->eat_cnt_sem);
	}
	sem_wait(philo->data->eat_sem);
	philo->last_time = ft_get_time();
	sem_post(philo->data->eat_sem);
	usleep_interval(philo->data->eat_time);
	if (philo->eat_cnt == philo->data->must_eat)
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
		exit(0);
	}
	ft_print_format(philo, "is sleeping");
	sem_post(philo->data->forks);
}

void	ft_thread(t_philo *philo)
{
	if (pthread_create(&philo->thread, 0, check_die, philo) != 0)
		exit(1);
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
	exit(0);
}

void	ft_parent(t_philo *philo, pid_t *pid_arr)
{
	int	status;
	int	i;

	i = 0;
	while (i < philo->data->philo_num)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < philo->data->philo_num)
			{
				kill(pid_arr[i], SIGKILL);
				i++;
			}
			exit(0);
		}
		i++;
	}
	printf("!!!\n");
}

int	run_philo(t_data *data, pid_t *pid_arr)
{
	int			i;
	long long	init_time;
	t_philo		philo;

	i = -1;
	init_time = ft_get_time();
	while (++i < data->philo_num)
	{
		philo.data = data;
		philo.init_time = init_time;
		philo.last_time = init_time;
		philo.id = i + 1;
		philo.eat_cnt = 0;
		philo.pid = fork();
		pid_arr[i] = philo.pid;
		if (philo.pid == -1)
			return (0);
		if (philo.pid == 0)
			break ;
	}
	if (philo.pid == 0)
		ft_thread(&philo);
	else
		ft_parent(&philo, pid_arr);
	return (1);
}
