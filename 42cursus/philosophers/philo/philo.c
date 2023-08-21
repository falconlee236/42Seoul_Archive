/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:44:11 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/21 13:46:15 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct timeval	t1;

	if (ac < 5 || ac > 6)
		return (0);
	gettimeofday(&t1, 0);
	printf("%ld %s\n", t1.tv_sec, av[0]);
}
