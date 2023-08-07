/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:48 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/07 22:02:01 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/ft_printf.h"

void	print_error(char *str)
{
	perror(str);
	exit(0);
}

// char	**make_argv(char *c_name)
// {
// 	size_t	size;
// 	char	**argv;

// 	size = (size_t)(ft_strchr(c_name, ' ') - c_name);
// 	argv = (char **)malloc(sizeof(char *) * 3);
// 	if (!argv)
// 		print_error("argv malloc error\n");
// 	argv[0] = ft_substr(c_name, 0, size);
// 	argv[1] = ft_substr(c_name, size + 1, ft_strlen(c_name) - size);
// 	argv[2] = NULL;
// 	printf("%s %s", argv[0], argv[1]);
// 	return (argv);
// }

void	run_command(char *c_name, char **path)
{
	int		i;
	char	*command;
	char	*command_dir;
	char	**argv;

	i = 0;
	// argv = make_argv(c_name);
	argv = ft_split(c_name, ' ');
	while (path[i])
	{
		command = ft_strjoin("/", argv[0]);
		command_dir = ft_strjoin(path[i++], command);
		if (access(command_dir, X_OK | F_OK) == 0)
			execve(command_dir, argv, NULL);
		free(command);
		free(command_dir);
	}
}

char	**pipe_init(int ac, char **env)
{
	int		i;
	char	**path;

	if (ac != 5 || !env || !(*env))
		print_error("invaild parameter\n");
	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", env[i], 4) == 0)
			path = ft_split(ft_strchr(env[i], '=') + 1, ':');
		i++;
	}
	if (!path)
		print_error("Path env variable parsing failed\n");
	return (path);
}

void	file1(char **path, char **av, int fds[2])
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("invaild file1\n");
	if (dup2(fd, 0) < 0)
		print_error("file1 function first dup2 error\n");
	if (dup2(fds[1], 1) < 0)
		print_error("file1 function second dup2 error\n");
	close(fd);
	close(fds[0]);
	run_command(av[2], path);
}

void	file2(char **path, char **av, int fds[2])
{
	int	fd;

	fd = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
		print_error("invaild file2\n");
	if (dup2(fd, 1) < 0)
		print_error("file2 function first dup2 error\n");
	if (dup2(fds[0], 0) < 0)
		print_error("file2 function second dup2 error\n");
	close(fd);
	close(fds[1]);
	run_command(av[3], path);
}

void	parents(int fds[2], int pid1, int pid2, char **path)
{
	int	i;

	i = 0;
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	while (path[i])
		free(path[i++]);
	free(path);
}

// void	leak_check(void)
// {
// 	system("leaks pipex");
// 	exit(0);
// }

int	main(int ac, char **av, char **env)
{
	char	**path;
	int		fds[2];
	pid_t	pid1;
	pid_t	pid2;

	// atexit(leak_check);
	path = pipe_init(ac, env);
	// char **ag = make_argv(av[3]);
	// printf("0=%s 1=%s 2=%s\n", ag[0], ag[1], ag[2]);
	if (pipe(fds) < 0)
		print_error("pipe error\n");
	pid1 = fork();
	if (pid1 < 0)
		print_error("fork error\n");
	if (pid1 == 0)
		file1(path, av, fds);
	else
	{
		pid2 = fork();
		if (pid2 < 0)
			print_error("fork error\n");
		if (pid2 == 0)
			file2(path, av, fds);
		else
			parents(fds, pid1, pid2, path);
	}
}
