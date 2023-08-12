/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:48:12 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/12 15:35:34 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *str)
{
	perror(str);
	exit(1);
}

void	free_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	run_command(char *c_name, char **path, char **env)
{
	int		i;
	char	*command;
	char	*command_dir;
	char	**argv;
	char	**tmp;

	i = 0;
	tmp = ft_split_mult(c_name, " \'\"");
	tmp[0] = c_name;
	if (access(c_name, X_OK | F_OK) == 0)
		execve(c_name, tmp, env);
	argv = ft_split_mult(c_name, " \'\"");
	while (path[i])
	{
		command = ft_strjoin("/", argv[0]);
		command_dir = ft_strjoin(path[i++], command);
		if (access(command_dir, X_OK | F_OK) == 0)
			execve(command_dir, argv, env);
		free(command);
		free(command_dir);
	}
	free_arr(path);
	print_error("pipex: error in run_command");
}

char	**make_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			path = ft_split(ft_strchr(env[i], '=') + 1, ':');
		i++;
	}
	if (!path)
		print_error("Path env variable parsing failed");
	return (path);
}
