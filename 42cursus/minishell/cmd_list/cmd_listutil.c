/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_listutil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:31:50 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 16:35:53 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

t_cmd	*cmd_createnew(void)
{
	t_cmd	*node;

	node = (t_cmd *)malloc(sizeof(t_cmd));
	if (!node)
		return (0);
	node->argv = 0;
	node->redirect = 0;
	node->prev = 0;
	node->next = 0;
	return (node);
}

t_cmd	*cmd_pushback(t_cmd **lst, t_cmd *new_node)
{
	t_cmd	*node;

	if (*lst)
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new_node;
		new_node->prev = node;
	}
	else
		*lst = new_node;
	return (new_node);
}

void	cmd_listclear(t_cmd **lst)
{
	t_cmd	*node;
	t_cmd	*cur;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		node = cur;
		free_2d_str_array(cur->argv);
		redirect_listclear(&(cur->redirect));
		cur = cur->next;
		free(node);
	}
	*lst = 0;
}
