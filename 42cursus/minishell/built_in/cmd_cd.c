/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 00:11:56 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 04:02:12 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	update_oldpwd(char *prev_path, t_env *env_list)
{
	char	*key;
	int		is_oldpwd_found;
	t_env	*node;

	is_oldpwd_found = 0;
	node = env_list;
	while (node)
	{
		key = get_env_key(node->str);
		if (key && ft_strcmp(key, "OLDPWD") == 0 && ++is_oldpwd_found)
			update_env(&(node->str), prev_path);
		four_times_free(key, 0, 0, 0);
		node = node->next;
	}
	if (!is_oldpwd_found)
		env_pushback(&env_list, env_createnew(prev_path));
	four_times_free(prev_path, 0, 0, 0);
	return (1);
}

static int	update_pwd(t_env *env_list)
{
	char	*key;
	char	*new_path;
	char	*tmp;
	int		is_pwd_found;
	t_env	*node;

	is_pwd_found = 0;
	node = env_list;
	tmp = getcwd(NULL, 0);
	new_path = ft_strjoin("PWD=", tmp);
	while (node)
	{
		key = get_env_key(node->str);
		if (key && ft_strcmp(key, "PWD") == 0 && ++is_pwd_found)
			update_env(&(node->str), new_path);
		four_times_free(key, 0, 0, 0);
		node = node->next;
	}
	if (!is_pwd_found)
		env_pushback(&env_list, env_createnew(new_path));
	four_times_free(new_path, tmp, 0, 0);
	return (1);
}

static void	check_arg(t_env *env_list, char **new_path,
	char **home_path, char **argv)
{
	*home_path = get_home_path(env_list);
	if (argv[1] == NULL || argv[1][0] == '~')
	{
		if (argv[1] == NULL)
			*new_path = ft_strdup(*home_path);
		else
			*new_path = ft_strjoin(*home_path, &argv[1][1]);
	}
	else if (ft_strcmp(argv[1], "-") == 0)
		*new_path = get_oldpwd(env_list);
	else
		*new_path = ft_strdup(argv[1]);
}

int	cmd_cd(char **argv, t_env *env_list)
{
	char	*home_path;
	char	*new_path;
	char	*prev_path;

	check_arg(env_list, &new_path, &home_path, argv);
	if ((argv[1] == NULL || argv[1][0] == '~') && home_path == NULL)
	{
		ft_putendl_fd("pmshell: cd: HOME not set", 2);
		return (1);
	}
	if (new_path == NULL)
		return (1);
	prev_path = get_pwd(env_list);
	if (chdir(new_path) != 0
		|| !update_pwd(env_list)
		|| !update_oldpwd(ft_strjoin("OLDPWD=", prev_path), env_list))
	{
		four_times_free(prev_path, new_path, home_path, 0);
		ft_putstr_fd("pmshell: ", 2);
		perror("cd");
		return (1);
	}
	four_times_free(prev_path, new_path, home_path, 0);
	return (0);
}
