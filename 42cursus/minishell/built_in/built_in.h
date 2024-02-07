/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:57:30 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 14:58:55 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H
# include "../pm_shell.h"

typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;
typedef struct s_token	t_token;

int		cmd_cd(char **argv, t_env *env_list);
int		cmd_echo(char **argv);
int		cmd_env(t_env *env_list);
int		cmd_exit(char **argv, t_cmd *cmd_list);
int		cmd_export(char **str, t_env *env_list);
int		cmd_pwd(void);
int		cmd_unset(char **argv, t_env *env_list);
int		exec_builtin(char **argv, t_cmd *cmd_list, t_env *env_list);
int		is_builtin(char **argv);
char	*get_home_path(t_env *env_list);
char	*get_oldpwd(t_env *env_list);
char	*get_pwd(t_env *env_list);

#endif
