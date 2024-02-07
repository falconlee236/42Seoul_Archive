/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_seperator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:44:16 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 17:03:25 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

static int	set_sep_idx(char *s, char *sep, int *start_idx, int *end_idx)
{
	(*start_idx) = 0;
	(*end_idx) = -1;
	while (s[*start_idx] && ft_strncmp(s + (*start_idx), sep, ft_strlen(sep)))
		(*start_idx)++;
	if (s[*start_idx] == '\0')
		return (0);
	(*end_idx) = (*start_idx) + ft_strlen(sep);
	return (1);
}

static char	**handle_seperator_with_strs(char *s, char *sep)
{
	int		start_idx;
	int		end_idx;
	char	**strs;

	if (!set_sep_idx(s, sep, &start_idx, &end_idx))
		return (0);
	strs = (char **)malloc(sizeof(char *) * 4);
	if (!strs)
		return (0);
	strs[0] = ft_substr(s, 0, start_idx);
	strs[1] = ft_substr(s, start_idx, end_idx - start_idx);
	strs[2] = ft_substr(s, end_idx, ft_strlen(s) - end_idx);
	strs[3] = 0;
	return (strs);
}

static void	make_token_in_seperator(t_token *token_list, char *sep, char **strs)
{
	t_token	*tmp;

	tmp = token_list->next;
	token_list->next = 0;
	free(token_list->str);
	token_list->str = ft_strdup(strs[0]);
	if (sep[0] == ' ')
		token_pushback(&token_list, token_createnew(strs[1], TOKEN_TYPE_SPACE));
	else if (sep[0] == '|')
	{
		token_pushback(&token_list,
			token_createnew(strs[1], TOKEN_TYPE_PIPELINE));
	}
	else
	{
		token_pushback(&token_list,
			token_createnew(strs[1], TOKEN_TYPE_REDIRECTION));
	}
	token_list = token_pushback(&token_list,
			token_createnew(strs[2], TOKEN_TYPE_CHUNK));
	free_2d_str_array(strs);
	token_list->next = tmp;
}

void	handle_seperator(t_token *token_list, char *sep)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = handle_seperator_with_strs(token_list->str, sep);
			if (strs)
			{
				make_token_in_seperator(token_list, sep, strs);
				continue ;
			}
		}
		token_list = token_list->next;
	}
}
