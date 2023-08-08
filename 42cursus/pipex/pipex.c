/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:48 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/08 21:52:36 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/ft_printf.h"

static void	file1(char **path, char **av, int fds[2], char **env)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		free_arr(path);
		print_error("pipex: input");
	}
	if (dup2(fd, 0) < 0)
	{
		close(fd);
		print_error("file1 function first dup2 error");
	}
	if (dup2(fds[1], 1) < 0)
	{
		close(fd);
		close(fds[1]);
		print_error("file1 function second dup2 error");
	}
	close(fd);
	close(fds[0]);
	run_command(av[2], path, env);
}

static void	file2(char **path, char **av, int fds[2], char **env)
{
	int	fd;

	fd = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		print_error("invaild file2\n");
	if (dup2(fd, 1) < 0)
	{
		close(fd);
		print_error("file2 function first dup2 error");
	}
	if (dup2(fds[0], 0) < 0)
	{
		close(fd);
		close(fds[0]);
		print_error("file2 function second dup2 error");
	}
	close(fd);
	close(fds[1]);
	run_command(av[3], path, env);
}

static void	parents(int fds[2], int pid1, int pid2, char **path)
{
	int	i;

	i = 0;
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	free_arr(path);
}

int	main(int ac, char **av, char **env)
{
	char	**path;
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	path = pipe_init(ac, env, fds);
	pid1 = fork();
	if (pid1 < 0)
		print_error("fork error");
	if (pid1 == 0)
		file1(path, av, fds, env);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			print_error("fork error");
		if (pid2 == 0)
			file2(path, av, fds, env);
		else
			parents(fds, pid1, pid2, path);
	}
    exit(0);
}
