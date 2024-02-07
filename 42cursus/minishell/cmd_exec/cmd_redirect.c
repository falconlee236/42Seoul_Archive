/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:58:11 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/05 19:36:04 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static int	redirect_input(t_redirect *redir, t_info *info)
{
	int		fd;
	char	*file_name;
	char	*file_num;

	if (ft_strcmp(redir->type, "<<") == 0)
	{
		file_num = ft_itoa(info->tmp_cnt);
		file_name = ft_strjoin(file_num, ".tmp");
		fd = open(file_name, O_RDONLY);
		four_times_free(file_name, file_num, 0, 0);
	}
	else
		fd = open(redir->file, O_RDONLY);
	if (fd == -1)
		exit_err(redir->file, 1, info);
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("dup2(stdin)");
	close(fd);
	return (1);
}

static int	redirect_output(t_redirect *redir, t_info *info)
{
	int	fd;

	if (ft_strcmp(redir->type, ">>") == 0)
		fd = open(redir->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(redir->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		exit_err(redir->file, 1, info);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("dup2(stdout)");
	close(fd);
	return (1);
}

int	redirect_io(t_cmd *cmd, t_info *info)
{
	int			res;
	t_redirect	*redir;

	if (cmd->redirect == NULL)
		return (1);
	redir = cmd->redirect;
	res = 1;
	while (redir && res)
	{
		if (ft_strcmp(redir->type, ">>") == 0
			|| ft_strcmp(redir->type, ">") == 0)
			res = redirect_output(redir, info);
		else
			res = redirect_input(redir, info);
		redir = redir->next;
	}
	return (res);
}
