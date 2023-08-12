/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:09:10 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/12 16:42:02 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "./libft/libft.h"
# include <unistd.h>
/*access() unlink() close() read() write() pipe() dup() dup2() execve() fork()*/
# include <fcntl.h>
/* open() */
# include <stdio.h>
/* perror() */
# include <string.h>
/* strerror */
# include <sys/wait.h>
/* waitpid() wait() */
# include <stdlib.h>
/* malloc() free() exit() */
# include <errno.h>

typedef struct s_pipes
{
	int		a[2];
	int		b[2];
	int		step;
	int		cnt;
	int		is_here;
	char	**path;
	pid_t	*pid_arr;
}	t_pipes;

void	print_error(char *str);
void	free_arr(char **arr);
void	run_command(char *c_name, char **path, char **env);
char	**make_path(char **env);

void	child_proc(t_pipes pipes, char **av, char **env);
void	parent_proc(t_pipes pipes);
#endif