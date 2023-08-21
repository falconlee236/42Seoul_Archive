/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:12:39 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/21 14:05:30 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* in mandatory */
# include <stdio.h> /* printf */
# include <stdlib.h> /* memset malloc free */
# include <unistd.h> /* write, usleep */
# include <sys/time.h> /* gettimeofday */
# include <pthread.h>
/* pthread_create, pthread_detach, pthread_join
 * pthread_mutex_init, pthread_mutex_destory,
 * pthread_mutex_lock, pthread_mutex_unlock */

typedef struct s_data
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}	t_data;
#endif