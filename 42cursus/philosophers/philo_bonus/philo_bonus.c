/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:44:11 by sangylee          #+#    #+#             */
/*   Updated: 2023/10/12 13:10:40 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str, int *f)
{
	int			i;
	int			flag;
	long long	res;

	i = 0;
	flag = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			flag = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i++] - '0';
		if (res >= 2147483647 || res < -2147483648)
		{
			*f = 1;
			return (0);
		}
	}
	return (res * flag);
}

int	ft_sem_init(t_data *data)
{
	data->forks = sem_open("forks", O_CREAT, 0644, data->philo_num);
	data->m_sem = sem_open("monitor", O_CREAT, 0644, 1);
	data->eat_sem = sem_open("eat", O_CREAT, 0644, 1);
	data->eat_cnt_sem = sem_open("eat_count", O_CREAT, 0644, 1);
	if (data->forks == SEM_FAILED || data->m_sem == SEM_FAILED
		|| data->eat_sem == SEM_FAILED || data->eat_cnt_sem == SEM_FAILED)
		return (0);
	return (1);
}

int	case_one(t_data *data)
{
	printf("\033[0;3%dm%d %d %s\n\033[0m", 1, 0, 1, "has taken a fork");
	usleep_interval(data->die_time);
	printf("\033[0;3%dm%d %d %s\n\033[0m", 1, data->die_time, 1, "is die");
	return (0);
}

int	philo_init(t_data *data, int ac, char **av)
{
	int	flag;

	flag = 0;
	data->philo_num = ft_atoi(av[1], &flag);
	data->die_time = ft_atoi(av[2], &flag);
	data->eat_time = ft_atoi(av[3], &flag);
	data->sleep_time = ft_atoi(av[4], &flag);
	if (data->die_time <= 0 || data->eat_time <= 0 || data->sleep_time <= 0)
		return (0);
	data->must_eat = -1;
	data->monitor = 0;
	data->total_eat_cnt = 0;
	if (ac == 6)
		data->must_eat = ft_atoi(av[5], &flag);
	if ((data->must_eat <= 0 && ac == 6) || flag)
		return (0);
	if (data->philo_num == 1)
		return (case_one(data));
	if (!ft_sem_init(data))
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	*philos;

	if (ac < 5 || ac > 6 || !philo_init(&data, ac, av))
		return (0);
	philos = (t_philo *)malloc(sizeof(t_philo) * data.philo_num);
	if (!philos)
		return (sem_close(data.forks));
	printf("%d\n", data.philo_num);
	sem_wait(data.forks);
	printf("1\n");
	sem_wait(data.forks);
	printf("2\n");
	sem_wait(data.forks);
	printf("3\n");
	sem_wait(data.forks);
	printf("4\n");
	sem_wait(data.forks);
	printf("5\n");
	sem_wait(data.forks);
	printf("6\n");
	run_philo(&data, philos);
	sem_close(data.m_sem);
	sem_close(data.eat_sem);
	sem_close(data.eat_cnt_sem);
	sem_close(data.forks);
	free(philos);
	return (0);
}
