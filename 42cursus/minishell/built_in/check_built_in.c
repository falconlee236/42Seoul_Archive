/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:57:07 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 14:55:51 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	exec_builtin(char **argv, t_cmd *cmd_list, t_env *env_list)
{
	if (!(argv[0]))
		return (0);
	else if (!ft_strcmp(argv[0], "cd"))
		return (cmd_cd(argv, env_list));
	else if (!ft_strcmp(argv[0], "echo"))
		return (cmd_echo(argv));
	else if (!ft_strcmp(argv[0], "env"))
		return (cmd_env(env_list));
	else if (!ft_strcmp(argv[0], "exit"))
		return (cmd_exit(argv, cmd_list));
	else if (!ft_strcmp(argv[0], "export"))
		return (cmd_export(argv, env_list));
	else if (!ft_strcmp(argv[0], "pwd"))
		return (cmd_pwd());
	else if (!ft_strcmp(argv[0], "unset"))
		return (cmd_unset(argv, env_list));
	return (0);
}

int	is_builtin(char **argv)
{
	if (!argv || !(argv[0]))
		return (0);
	else if (!ft_strcmp(argv[0], "cd")
		|| !ft_strcmp(argv[0], "echo")
		|| !ft_strcmp(argv[0], "env")
		|| !ft_strcmp(argv[0], "export")
		|| !ft_strcmp(argv[0], "pwd")
		|| !ft_strcmp(argv[0], "unset")
		|| !ft_strcmp(argv[0], "exit"))
		return (1);
	return (0);
}
