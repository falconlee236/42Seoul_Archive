/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_single.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:46:11 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 15:18:25 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static void	exec_child_cmd(t_cmd *cmd, t_info *info)
{
	pid_t	pid;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pid = fork();
	if (pid < 0)
		exit_err("fork", 1, info);
	else if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		redirect_io(cmd, info);
		exec_command(cmd, info);
	}
	cmd_wait_child(pid, 1, info);
}

void	exec_single_cmd(t_cmd *cmd, t_info *info)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (is_builtin(cmd->argv))
	{
		redirect_io(cmd, info);
		info->status_code = exec_builtin(cmd->argv, cmd, info->env_list);
	}
	else
		exec_child_cmd(cmd, info);
}
