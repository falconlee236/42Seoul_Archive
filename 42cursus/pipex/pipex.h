/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:09:10 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/08 21:48:48 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

void	print_error(char *str);
void	free_arr(char **arr);
void	run_command(char *c_name, char **path, char **env);
char	**pipe_init(int ac, char **env, int fds[2]);
#endif