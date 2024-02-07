/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:39:09 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/05 19:17:06 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static void	reset_fd_signal(t_info *info)
{
	if (dup2(info->stdin_fd, STDIN_FILENO) == -1)
		exit_msg("FD Error", info);
	if (dup2(info->stdout_fd, STDOUT_FILENO) == -1)
		exit_msg("FD Error", info);
	close(info->stdin_fd);
	close(info->stdout_fd);
	init_sig_handler();
}

static int	get_cmd_cnt(t_cmd *cmd_list)
{
	int	i;

	i = 0;
	while (cmd_list)
	{
		i++;
		cmd_list = cmd_list->next;
	}
	return (i);
}

void	exec_cmd_list(t_cmd *cmd_list, t_info *info)
{
	int		cmd_cnt;
	pid_t	pid;

	info->stdin_fd = dup(STDIN_FILENO);
	info->stdout_fd = dup(STDOUT_FILENO);
	cmd_cnt = get_cmd_cnt(cmd_list);
	pid = fork();
	if (pid == 0)
		exec_heredoc(cmd_list, info);
	signal(SIGINT, SIG_IGN);
	wait(&info->status_code);
	if (WIFEXITED(info->status_code))
		info->status_code = WEXITSTATUS(info->status_code);
	if (WIFSIGNALED(info->status_code))
	{
		info->status_code = 1;
		unlink_heredoc_tmp(cmd_list);
		return (reset_fd_signal(info));
	}
	if (get_cmd_cnt(cmd_list) > 1)
		exec_multiple_cmd(cmd_list, info, cmd_cnt);
	else
		exec_single_cmd(cmd_list, info);
	unlink_heredoc_tmp(cmd_list);
	reset_fd_signal(info);
}
