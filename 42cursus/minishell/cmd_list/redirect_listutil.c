/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_listutil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 19:47:06 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 17:05:15 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_redirect	*redirect_createnew(char *file, char *type)
{
	t_redirect	*node;

	node = (t_redirect *)malloc(sizeof(t_redirect));
	if (!node)
		return (0);
	node->file = ft_strdup(file);
	node->type = ft_strdup(type);
	node->next = 0;
	return (node);
}

void	redirect_pushback(t_redirect **lst, t_redirect *new_node)
{
	t_redirect	*node;

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

void	redirect_listclear(t_redirect **lst)
{
	t_redirect	*node;
	t_redirect	*cur;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		node = cur;
		free(cur->file);
		free(cur->type);
		cur = cur->next;
		free(node);
	}
	*lst = 0;
}
