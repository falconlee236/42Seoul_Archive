/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 06:47:15 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/02 02:56:51 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

char	*get_full_path_cmd(char *cmd, char **env_path)
{
	char	*res;
	char	*tmp;
	int		i;

	i = 0;
	while (env_path && env_path[i])
	{
		tmp = ft_strjoin(env_path[i], "/");
		if (!tmp)
			exit(1);
		res = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!res)
			exit(1);
		if (access(res, X_OK) == 0)
			return (res);
		free(res);
		i++;
	}
	return (NULL);
}
