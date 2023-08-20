/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:12:21 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/16 19:14:48 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
    struct timeval  t1;
	if (ac < 5 || ac > 6)
        return (0);
    gettimeofday(&t1, 0);
    printf("%ld %s\n", t1.tv_sec, av[0]);
}
