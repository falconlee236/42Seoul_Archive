/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 02:54:31 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 15:39:29 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

void	exit_dot_err(char *cmd, t_info *info)
{
	if (ft_strcmp(cmd, ".") == 0)
	{
		ft_putendl_fd("pmshell: .: filename argument required", 2);
		ft_putendl_fd(".: usage: . filename [arguments]", 2);
		info->status_code = 2;
		exit(2);
	}
	if (ft_strcmp(cmd, "..") == 0)
		exit_no_path(cmd, info);
}

void	exit_no_path(char *cmd, t_info *info)
{
	int	is_dir;

	is_dir = 0;
	ft_putstr_fd("pmshell: ", 2);
	if (access(cmd, X_OK) == 0 && ++is_dir)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": is a directory", 2);
	}
	else
	{
		info->status_code = 126;
		perror(cmd);
		exit(126);
	}
	if (is_dir)
	{
		info->status_code = 126;
		exit(126);
	}
	info->status_code = 127;
	exit(127);
}

void	exit_not_found(char *cmd, t_info *info)
{
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(": Command not found", 2);
	info->status_code = 127;
	exit(127);
}

void	exit_err(char *cmd, int err, t_info *info)
{
	ft_putstr_fd("pmshell: ", 2);
	perror(cmd);
	info->status_code = err;
	exit(err);
}

void	exit_msg(char *str, t_info *info)
{
	ft_putstr_fd("pmshell: ", 2);
	ft_putendl_fd(str, 2);
	info->status_code = 1;
	exit(1);
}
