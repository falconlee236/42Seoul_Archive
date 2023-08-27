/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/08/27 16:24:51 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("im a %d thread!!\n", philo->id);
	return (arg);
}

int	ft_philo_init(t_philo *philo, int id)
{
	philo->id = id;
	philo->left = id;
	philo->right = (id + 1) % philo->data.philo_num;
	philo->eat_cnt = 0;
	pthread_create(&philo->thread, 0, ft_thread, &philo[id]);
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
