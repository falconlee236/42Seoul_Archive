/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_multiple.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 05:46:35 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 15:33:41 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static void	exec_child(t_cmd *cmd, t_info *info, int last_process)
{
	int	res;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	close(cmd->pipe[0]);
	if (last_process != 0 && dup2(cmd->pipe[1], 1) == -1)
		perror("dup2(pipe_write)");
	close(cmd->pipe[1]);
	redirect_io(cmd, info);
	if (is_builtin(cmd->argv))
	{
		res = exec_builtin(cmd->argv, cmd, info->env_list);
		exit(res);
	}
	else
		exec_command(cmd, info);
}

static void	exec_parent(t_cmd *cmd)
{
	close(cmd->pipe[1]);
	if (dup2(cmd->pipe[0], 0) == -1)
		perror("dup2(stdin)");
	close(cmd->pipe[0]);
}

void	exec_multiple_cmd(t_cmd *cmd, t_info *info, int cmd_cnt)
{
	pid_t	pid;
	int		idx;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	idx = 1;
	while (cmd)
	{
		if (pipe(cmd->pipe) == -1)
			exit_msg("Pipe Error", info);
		pid = fork();
		if (pid == -1)
			exit_msg("Fork Error", info);
		else if (pid == 0)
			exec_child(cmd, info, cmd_cnt - idx);
		else
			exec_parent(cmd);
		cmd = cmd->next;
		info->tmp_cnt = idx;
		idx++;
	}
	cmd_wait_child(pid, cmd_cnt, info);
}
