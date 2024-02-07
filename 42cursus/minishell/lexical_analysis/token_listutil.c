/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_listutil.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:11:54 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 16:28:46 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

t_token	*token_createnew(char *token_str, t_token_type token_type)
{
	t_token	*node;

	node = (t_token *)malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->str = ft_strdup(token_str);
	node->type = token_type;
	node->next = NULL;
	return (node);
}

t_token	*token_pushback(t_token **lst, t_token *new_node)
{
	t_token	*node;

	if (*lst)
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*lst = new_node;
	return (new_node);
}

void	token_listclear(t_token **lst)
{
	t_token	*node;
	t_token	*cur;

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

t_token	*token_delete(t_token **lst, t_token *token)
{
	t_token	*cur;
	t_token	*prev;

	if (!lst)
		return (0);
	cur = *lst;
	prev = cur;
	if (cur == token)
	{
		cur = cur->next;
		free(prev->str);
		free(prev);
		*lst = cur;
		return (cur);
	}
	while (cur && cur->next != token)
		cur = cur->next;
	prev = cur;
	cur = cur->next;
	prev->next = cur->next;
	free(cur->str);
	free(cur);
	return (prev);
}

int	is_tokenable_sep(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>' || c == '\0');
}
