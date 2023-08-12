/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 12:58:03 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/12 20:57:29 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/get_next_line.h"

static	void	make_tmpfile(char *limiter)
{
	int		fd;
	char	*line;

	fd = open("tmpfile", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		print_error("pipex: tmp file open error");
	line = "";
	while (ft_strncmp(limiter, line, ft_strlen(limiter)))
	{
		line = get_next_line(0);
		ft_putstr_fd(line, fd);
		free(line);
	}
	close(fd);
}

static	void	pipex_init(t_pipes *pipes, int ac, char **av, char **env)
{
	if (ft_strncmp("here_doc", av[1], 8) == 0 && ft_strlen(av[1]) == 8)
	{
		pipes->is_here = 1;
		pipes->cnt = ac - 4;
		make_tmpfile(av[2]);
	}
	else
	{
		pipes->is_here = 0;
		pipes->cnt = ac - 3;
	}
	pipes->step = -1;
	pipes->path = make_path(env);
	pipes->pid_arr = (pid_t *)malloc(sizeof(pid_t) * (pipes->cnt + 1));
	pipes->pid_arr[pipes->cnt] = 0;
}

void	wait_proc(t_pipes pipes)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (cnt != pipes.cnt)
	{
		if (waitpid(pipes.pid_arr[i % pipes.cnt], 0, 0)
			== pipes.pid_arr[i % pipes.cnt])
			cnt++;
		i++;
	}
	free_arr(pipes.path);
	free(pipes.pid_arr);
	unlink("tmpfile");
}

int	main(int ac, char **av, char **env)
{
	t_pipes	pipes;
	pid_t	pid;

	if (ac < 5)
		print_error("pipex: too less arguments");
	pipex_init(&pipes, ac, av, env);
	while (++pipes.step < pipes.cnt)
	{
		if (!(pipes.step % 2) && pipe(pipes.a) < 0)
			print_error("pipex: pipeA error");
		if ((pipes.step % 2) && pipe(pipes.b) < 0)
			print_error("pipex: pipeB error");
		pid = fork();
		if (pid == -1)
			print_error("pipex: fork error");
		else if (!pid)
			child_proc(pipes, av, env);
		else
		{
			pipes.pid_arr[pipes.step] = pid;
			parent_proc(pipes);
		}
	}
	wait_proc(pipes);
}
