/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:04:52 by sangylee          #+#    #+#             */
/*   Updated: 2023/10/22 12:51:18 by sangylee         ###   ########.fr       */
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
	sem_t	*print_sem;
}	t_data;

typedef struct s_philo
{
	pid_t		pid;
	int			id;
	int			eat_cnt;
	long long	init_time;
	long long	last_time;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

int			run_philo(t_data *data, pid_t *pid_arr);
void		*check_die(void *args);
long long	ft_get_time(void);
void		usleep_interval(long long t);
void		ft_print_format(t_philo *philo, char *format);
#endif