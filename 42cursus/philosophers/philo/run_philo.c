/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/08/25 00:56:02 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	return (arg);
}

int	ft_philo_init(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->left = id;
	philo->right = (id + 1) % data->philo_num;
	pthread_create(&philo->thread, 0, ft_thread, (void *)0);
	return (1);
}

int	run_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		if (!ft_philo_init(data, &data->philos[i], i))
			return (0);
	}
	return (1);
}
