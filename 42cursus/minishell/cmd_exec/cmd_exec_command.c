/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 00:41:03 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/05 18:46:06 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static void	check_dot_command(t_cmd *cmd, char **env_list, t_info *info)
{
	if (cmd->argv[0][0] != '.' && cmd->argv[0][0] != '/')
		return ;
	if (cmd->argv[0][0] == '.')
	{
		exit_dot_err(cmd->argv[0], info);
		if ((cmd->argv[0][1] == '.' && cmd->argv[0][2] != '/')
			|| (cmd->argv[0][1] != '/' && cmd->argv[0][1] != '.'))
			return ;
	}
	execve(cmd->argv[0], cmd->argv, env_list);
	exit_no_path(cmd->argv[0], info);
}

void	exec_command(t_cmd *cmd, t_info *info)
{
	char	**env_str_list;
	char	**path_list;
	char	*full_cmd;

	if (cmd->argv == NULL || cmd->argv[0] == NULL)
		exit(1);
	env_str_list = get_env_str_list(info->env_list);
	path_list = get_path_env(info->env_list);
	if (path_list == NULL || path_list[0] == NULL)
	{
		execve(cmd->argv[0], cmd->argv, env_str_list);
		exit_no_path(cmd->argv[0], info);
	}
	check_dot_command(cmd, env_str_list, info);
	full_cmd = get_full_path_cmd(cmd->argv[0], path_list);
	if (full_cmd == NULL)
		exit_not_found(cmd->argv[0], info);
	execve(full_cmd, cmd->argv, env_str_list);
	free_2d_str_array(env_str_list);
	free_2d_str_array(path_list);
	exit_err(cmd->argv[0], 1, info);
}
