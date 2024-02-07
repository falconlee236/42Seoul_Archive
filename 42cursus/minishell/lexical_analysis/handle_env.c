/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:45:26 by sangylee          #+#    #+#             */
/*   Updated: 2024/02/05 17:41:22 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

static char	**handle_env_with_question_mark(t_info *info)
{
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * 4);
	if (!strs)
		return (0);
	strs[0] = ft_itoa(info->status_code);
	strs[1] = ft_strdup(" ");
	strs[2] = ft_strdup("");
	strs[3] = 0;
	return (strs);
}

static char	**find_value_in_env_without_quote(
	t_info *info, char *s, int dollor_idx, int next_idx)
{
	char	**strs;
	char	*env_value;
	int		space_idx;

	strs = (char **)malloc(sizeof(char *) * 4);
	if (!strs)
		return (0);
	env_value = ft_substr(s, dollor_idx + 1, next_idx - dollor_idx - 1);
	env_value = find_value_in_env(info->env_list, env_value);
	space_idx = 0;
	while (env_value[space_idx] && env_value[space_idx] != ' ')
		space_idx++;
	strs[0] = ft_substr(env_value, 0, space_idx);
	strs[1] = ft_strdup(" ");
	strs[2] = ft_substr(env_value, space_idx + 1,
			ft_strlen(env_value) - space_idx - 1);
	strs[3] = 0;
	free(env_value);
	return (strs);
}

static char	**handle_env_without_quote(t_info *info, char *s)
{
	char	**strs;
	int		dollor_idx;
	int		next_idx;
	char	**tmps;

	if (!set_dollor_idx(s, &dollor_idx, &next_idx))
		return (0);
	strs = (char **)malloc(sizeof(char *) * 6);
	if (!strs)
		return (0);
	strs[0] = ft_substr(s, 0, dollor_idx);
	if (s[dollor_idx + 1] == '?')
		tmps = handle_env_with_question_mark(info);
	else
		tmps = find_value_in_env_without_quote(info, s, dollor_idx, next_idx);
	strs[1] = ft_strdup(tmps[0]);
	strs[2] = ft_strdup(tmps[1]);
	strs[3] = ft_strdup(tmps[2]);
	strs[4] = ft_substr(s, next_idx, ft_strlen(s) - next_idx);
	strs[5] = 0;
	free_2d_str_array(tmps);
	return (strs);
}

static void	make_token_in_env(t_token *token_list, char **strs)
{
	t_token	*tmp;

	tmp = token_list->next;
	token_list->next = 0;
	free(token_list->str);
	token_list->str = ft_strdup(strs[0]);
	if (strs[1][0])
		token_pushback(&token_list, token_createnew(strs[1], TOKEN_TYPE_ARGV));
	if (strs[3][0])
	{
		token_pushback(&token_list, token_createnew(strs[2], TOKEN_TYPE_SPACE));
		token_pushback(&token_list, token_createnew(strs[3], TOKEN_TYPE_ARGV));
	}
	token_list = token_pushback(&token_list,
			token_createnew(strs[4], TOKEN_TYPE_CHUNK));
	free_2d_str_array(strs);
	token_list->next = tmp;
}

void	handle_env(t_info *info, t_token *token_list)
{
	char	**strs;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = handle_env_without_quote(info, token_list->str);
			if (strs)
				make_token_in_env(token_list, strs);
		}
		token_list = token_list->next;
	}
}
