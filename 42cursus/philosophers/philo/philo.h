/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:12:39 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/25 00:36:18 by isang-yun        ###   ########.fr       */
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

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	pthread_t	thread;
}	t_philo;

typedef struct s_data
{
	int				philo_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	t_philo			*philos;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
}	t_data;

int	run_philo(t_data *data);
#endif