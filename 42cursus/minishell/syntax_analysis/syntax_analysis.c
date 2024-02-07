/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:35:37 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 16:54:27 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../pm_shell.h"

static int	check_pipe_syntax(t_token *token_list)
{
	t_token	*prev;

	prev = 0;
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_PIPELINE
			&& (prev == 0 || token_list->next == 0
				|| token_list->next->type == TOKEN_TYPE_PIPELINE))
			return (0);
		prev = token_list;
		token_list = token_list->next;
	}
	return (1);
}

static int	check_redirection_syntax(t_token *token_list)
{
	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_REDIRECTION
			&& (token_list->next == 0
				|| token_list->next->type != TOKEN_TYPE_ARGV))
			return (0);
		token_list = token_list->next;
	}
	return (1);
}

int	syntax_analysis(t_token *token_list)
{
	if (check_pipe_syntax(token_list)
		&& check_redirection_syntax(token_list))
		return (1);
	return (0);
}
