/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmdlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:13:59 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 17:05:02 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_list.h"

static int	get_argv_cnt(t_token *token_list)
{
	int	cnt;

	cnt = 0;
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		if (token_list->type == TOKEN_TYPE_ARGV)
			cnt++;
		if (token_list->type == TOKEN_TYPE_REDIRECTION)
			cnt--;
		token_list = token_list->next;
	}
	return (cnt);
}

static char	**make_argvlist(t_token *token_list)
{
	int		idx;
	char	**argv_list;

	idx = 0;
	argv_list = (char **)malloc(sizeof(char *) * (get_argv_cnt(token_list)+1));
	if (argv_list == 0)
		return (0);
	while (token_list && token_list->type != TOKEN_TYPE_PIPELINE)
	{
		if (token_list->type == TOKEN_TYPE_ARGV)
			argv_list[idx++] = ft_strdup(token_list->str);
		if (token_list->type == TOKEN_TYPE_REDIRECTION)
			token_list = token_list->next;
		token_list = token_list->next;
	}
	argv_list[idx] = 0;
	return (argv_list);
}

t_cmd	*make_cmdlist(t_token *token_list)
{
	t_cmd	*cmd_list;
	t_cmd	*head;
	char	*file_name;

	cmd_list = cmd_createnew();
	head = cmd_list;
	while (token_list)
	{
		if (cmd_list->argv == 0 && token_list->type == TOKEN_TYPE_ARGV)
			cmd_list->argv = make_argvlist(token_list);
		else if (token_list->type == TOKEN_TYPE_REDIRECTION)
		{
			file_name = token_list->next->str;
			redirect_pushback(&(cmd_list->redirect),
				redirect_createnew(file_name, token_list->str));
			token_list = token_list->next;
		}
		else if (token_list->type == TOKEN_TYPE_PIPELINE)
			cmd_list = cmd_pushback(&cmd_list, cmd_createnew());
		token_list = token_list->next;
	}
	return (head);
}
