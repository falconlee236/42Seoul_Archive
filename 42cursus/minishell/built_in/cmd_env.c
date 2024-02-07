/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:02:34 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 03:02:52 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	cmd_env(t_env *env_list)
{
	char	*tmp;

	while (env_list)
	{
		tmp = get_env_value(env_list->str);
		if (tmp)
		{
			printf("%s\n", env_list->str);
			free(tmp);
		}
		env_list = env_list->next;
	}
	return (0);
}
