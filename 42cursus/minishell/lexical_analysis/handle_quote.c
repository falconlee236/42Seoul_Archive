/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 11:02:31 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/21 17:03:30 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

static int	set_quote_index(t_info *info, char *s, int *start_idx, int *end_idx)
{
	*start_idx = 0;
	while (s[*start_idx] && s[*start_idx] != '\'' && s[*start_idx] != '\"')
		(*start_idx)++;
	if (s[*start_idx] == '\0')
		return (1);
	*end_idx = *start_idx + 1;
	while (s[*end_idx] && s[*start_idx] != s[*end_idx])
		(*end_idx)++;
	if (s[*end_idx] == '\0')
	{
		ft_putstr_fd("pm_shell: quotes error in argument\n", STDERR_FILENO);
		info->is_error = 1;
		return (1);
	}
	return (0);
}

static char	**handle_quote_in_chunk(t_info *info, char *s)
{
	int		start_idx;
	int		end_idx;
	char	**strs;

	strs = (char **)malloc(sizeof(char *) * 4);
	if (!strs)
		return (NULL);
	if (set_quote_index(info, s, &start_idx, &end_idx))
	{
		free(strs);
		return (NULL);
	}
	if (start_idx > 0 && s[start_idx - 1] == '$')
		strs[0] = ft_substr(s, 0, start_idx - 1);
	else
		strs[0] = ft_substr(s, 0, start_idx);
	strs[1] = ft_substr(s, start_idx + 1, end_idx - start_idx - 1);
	if (s[start_idx] == '\"')
		strs[1] = handle_double_quote_with_env(info, strs[1]);
	strs[2] = ft_substr(s, end_idx + 1, ft_strlen(s) - end_idx - 1);
	strs[3] = NULL;
	return (strs);
}

void	handle_quote(t_info *info, t_token *token_list)
{
	char	**strs;
	t_token	*tmp;

	while (token_list)
	{
		if (token_list->type == TOKEN_TYPE_CHUNK)
		{
			strs = handle_quote_in_chunk(info, token_list->str);
			if (strs)
			{
				tmp = token_list->next;
				token_list->next = NULL;
				free(token_list->str);
				token_list->str = ft_strdup(strs[0]);
				token_pushback(&token_list,
					token_createnew(strs[1], TOKEN_TYPE_ARGV));
				token_list = token_pushback(&token_list,
						token_createnew(strs[2], TOKEN_TYPE_CHUNK));
				token_list->next = tmp;
				free_2d_str_array(strs);
				continue ;
			}
		}
		token_list = token_list->next;
	}
}

//cat << $"USER" -e > a | echo "$USER"$USER"$USER"$USER
