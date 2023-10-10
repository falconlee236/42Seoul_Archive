/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:04:52 by sangylee          #+#    #+#             */
/*   Updated: 2023/10/11 00:51:25 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
/* in bonus */
# include <stdio.h> // printf
# include <stdlib.h> // memset, malloc, free, exit
# include <unistd.h> // fork, write, usleep
# include <sys/wait.h> //waitpid
# include <signal.h> // kill
# include <sys/time.h> // gettimeofday
# include <pthread.h> // pthread_create, pthread_detach, pthread_join
# include <semaphore.h>
// sem_open, sem_close, sem_post, sem_wait, sem_unlink

typedef struct s_data
{
	int		philo_num;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		must_eat;
	int		monitor;
	int		total_eat_cnt;
	sem_t	*forks;
	sem_t	*m_sem;
	sem_t	*eat_sem;
	sem_t	*eat_cnt_sem;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	init_time;
	long long	last_time;
	pid_t		thread;
	t_data		*data;
}	t_philo;

int			run_philo(t_data *data, t_philo *philos);

long long	ft_get_time(void);
void		check_die(t_data *data, t_philo *philos);
void		usleep_interval(long long t);
void		ft_print_format(t_philo *philo, char *format);
#endif