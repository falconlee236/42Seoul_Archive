/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:58:50 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/14 13:37:46 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_start(t_pipes pipes, char **av, char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("pipex: input file open error in first");
	if (dup2(fd, 0) < 0)
		print_error("pipex: dup2 error stdin to input in first");
	close(fd);
	if (dup2(pipes.a[1], 1) < 0)
		print_error("pipex: dup2 error stdout to pipeA in first");
	close(pipes.a[0]);
	run_command(av[pipes.step + 2], pipes.path, env);
}

static void	child_end(t_pipes pipes, char **av, char **env)
{
	int	fd;

	fd = open(av[pipes.cnt + 2], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		print_error("pipex: output file open error in end");
	if (!(pipes.step % 2))
	{
		if (dup2(pipes.b[0], 0) < 0)
			print_error("pipex: dup2 error stdin to pipeB in end");
		close(pipes.b[1]);
	}
	else
	{
		if (dup2(pipes.a[0], 0) < 0)
			print_error("pipex: dup2 error stdin to pipeA in end");
		close(pipes.a[1]);
	}
	if (dup2(fd, 1) < 0)
		print_error("pipex: dup2 error stdout to pipeA in end");
	close(fd);
	run_command(av[pipes.step + 2], pipes.path, env);
}

static void	child_middle(t_pipes pipes, char **av, char **env)
{
	if (!(pipes.step % 2))
	{
		if (dup2(pipes.a[1], 1) < 0)
			print_error("pipex: dup2 error stdout to pipeA in middle");
		close(pipes.a[0]);
		if (dup2(pipes.b[0], 0) < 0)
			print_error("pipex: dup2 error stdin to pipeB in middle");
		close(pipes.b[1]);
		run_command(av[pipes.step + 2], pipes.path, env);
	}
	else
	{
		if (dup2(pipes.b[1], 1) < 0)
			print_error("pipex: dup2 error stdout to pipeB in middle");
		close(pipes.b[0]);
		if (dup2(pipes.a[0], 0) < 0)
			print_error("pipex: dup2 error stdin to pipeA in middle");
		close(pipes.a[1]);
		run_command(av[pipes.step + 2], pipes.path, env);
	}
}

void	child_proc(t_pipes pipes, char **av, char **env)
{
	if (pipes.step == 0)
		child_start(pipes, av, env);
	else if (pipes.step == pipes.cnt - 1)
		child_end(pipes, av, env);
	else
		child_middle(pipes, av, env);
}
