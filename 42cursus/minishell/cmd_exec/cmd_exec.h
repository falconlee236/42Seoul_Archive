/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:38:37 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/05 19:32:55 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_EXEC_H
# define CMD_EXEC_H
# include "../pm_shell.h"

typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;
typedef struct s_info	t_info;

int		redirect_io(t_cmd *cmd, t_info *info);
char	*get_full_path_cmd(char *cmd, char **env_path);
void	cmd_wait_child(pid_t pid_parent, int cmd_cnt, t_info *info);
void	exec_multiple_cmd(t_cmd *cmd, t_info *info, int cmd_cnt);
void	exec_single_cmd(t_cmd *cmd, t_info *info);
void	exec_cmd_list(t_cmd *cmd_list, t_info *info);
void	exec_command(t_cmd *cmd, t_info *info);
void	exec_heredoc(t_cmd *cmd_list, t_info *info);
void	exit_dot_err(char *cmd, t_info *info);
void	exit_err(char *cmd, int err, t_info *info);
void	exit_msg(char *str, t_info *info);
void	exit_no_path(char *cmd, t_info *info);
void	exit_not_found(char *cmd, t_info *info);
void	unlink_heredoc_tmp(t_cmd *cmd_list);
#endif
