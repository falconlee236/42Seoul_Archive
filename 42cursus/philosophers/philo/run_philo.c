/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:16:43 by isang-yun         #+#    #+#             */
/*   Updated: 2023/08/25 00:44:29 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_thread(void)
{
	return (1);
}

int	ft_philo_init(t_data *data, t_philo *philo, int id)
{
	philo->id = id;
	philo->left = id;
	philo->right = (id + 1) % data->philo_num;
	pthread_create(&philo->thread, 0, ft_thread, 0);
}

int	run_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (!ft_pthread_init(data, &data->philos[i], i++))
			return (0);
	}
}
