/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_listutil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:11:54 by sangylee          #+#    #+#             */
/*   Updated: 2024/02/05 21:20:02 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

t_env	*make_envlist(char **env)
{
	int		i;
	t_env	*env_list;

	i = -1;
	env_list = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "OLDPWD", 6) == 0)
			continue ;
		env_pushback(&env_list, env_createnew(env[i]));
	}
	return (env_list);
}

t_env	*env_createnew(char *s)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->str = ft_strdup(s);
	node->next = NULL;
	return (node);
}

void	env_pushback(t_env **lst, t_env *new_node)
{
	t_env	*node;

	if (*lst)
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*lst = new_node;
}

void	env_listclear(t_env **lst)
{
	t_env	*node;
	t_env	*cur;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		node = cur;
		free(cur->str);
		cur = cur->next;
		free(node);
	}
	*lst = NULL;
}
