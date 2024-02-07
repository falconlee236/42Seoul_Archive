/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:48:59 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 03:49:54 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

char	*get_home_path(t_env *env_list)
{
	char	*key;

	while (env_list)
	{
		key = get_env_key(env_list->str);
		if (key && ft_strcmp(key, "HOME") == 0)
		{
			free(key);
			return (get_env_value(env_list->str));
		}
		four_times_free(key, 0, 0, 0);
		env_list = env_list->next;
	}
	return (NULL);
}

char	*get_oldpwd(t_env *env_list)
{
	char	*key;

	while (env_list)
	{
		key = get_env_key(env_list->str);
		if (key && ft_strcmp(key, "OLDPWD") == 0)
		{
			free(key);
			return (get_env_value(env_list->str));
		}
		four_times_free(key, 0, 0, 0);
		env_list = env_list->next;
	}
	return (ft_strdup(""));
}

char	*get_pwd(t_env *env_list)
{
	char	*key;

	while (env_list)
	{
		key = get_env_key(env_list->str);
		if (key && ft_strcmp(key, "PWD") == 0)
		{
			free(key);
			return (get_env_value(env_list->str));
		}
		four_times_free(key, 0, 0, 0);
		env_list = env_list->next;
	}
	return (ft_strdup(""));
}
