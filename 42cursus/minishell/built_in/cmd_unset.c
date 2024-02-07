/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:02:34 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 03:36:59 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	del_env(char *str, t_env **env_list)
{
	t_env	*cur;
	t_env	*prev;

	cur = *env_list;
	if (is_target_env(str, cur->str))
	{
		*env_list = (*env_list)->next;
		four_times_free(cur->str, (char *)cur, 0, 0);
		return ;
	}
	prev = *env_list;
	while (cur)
	{
		if (is_target_env(str, cur->str))
		{
			prev->next = cur->next;
			four_times_free(cur->str, (char *)cur, 0, 0);
			return ;
		}
		prev = cur;
		cur = cur->next;
	}
}

int	cmd_unset(char **argv, t_env *env_list)
{
	int		i;

	i = 1;
	while (env_list && argv[i])
	{
		if (is_valid_env_key(argv[i], 1))
			del_env(argv[i], &env_list);
		else
			print_argument_err(argv[i]);
		i++;
	}
	return (0);
}
