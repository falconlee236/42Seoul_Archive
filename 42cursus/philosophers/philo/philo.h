/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:12:39 by sangylee          #+#    #+#             */
/*   Updated: 2023/09/12 15:15:30 by isang-yun        ###   ########.fr       */
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
	int				monitor;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	init_time;
	long long	last_time;
	pthread_t	thread;
	t_data		data;
}	t_philo;

int			run_philo(t_data *data, t_philo *philos);

long long	ft_get_time(void);
int			check_die(t_philo *philo);
void		usleep_interval(long long t);
void		ft_print_format(t_philo *philo, char *format, int fork);
#endif