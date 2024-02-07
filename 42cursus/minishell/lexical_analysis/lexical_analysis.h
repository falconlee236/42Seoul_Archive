/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analysis.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 15:59:55 by yonyoo            #+#    #+#             */
/*   Updated: 2024/01/29 13:20:57 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYSIS_H
# define LEXICAL_ANALYSIS_H

# include "../pm_shell.h"

typedef struct s_env	t_env;
typedef struct s_info	t_info;

/*NOTE
	TOKEN_TYPE_CHUNK,// 해석될 여지가 아직 존재하는 단계
	TOKEN_TYPE_ARGV,// 더이상 해석할 수 없는 단계
	TOKEN_TYPE_SPACE,// 빈칸
	TOKEN_TYPE_PIPELINE,// 파이프
	TOKEN_TYPE_REDIRECTION// 리다이렉션
*/
typedef enum e_token_type
{
	TOKEN_TYPE_CHUNK,
	TOKEN_TYPE_ARGV,
	TOKEN_TYPE_SPACE,
	TOKEN_TYPE_PIPELINE,
	TOKEN_TYPE_REDIRECTION
}t_token_type;

/*NOTE
	type: 해당 토큰의 타입
	str: 해당 토큰의 문자열
	next: 다음 토큰을 가리킴
*/
typedef struct s_token
{
	t_token_type	type;
	char			*str;
	struct s_token	*next;
}t_token;

t_token		*lexical_analysis(t_info *info, char *s);
void		handle_heredoc(t_info *info, t_token *token_list);

int			is_tokenable_sep(char c);
t_token		*token_createnew(char *token_str, t_token_type token_type);
t_token		*token_pushback(t_token **lst, t_token *new);
void		token_listclear(t_token **lst);
t_token		*token_delete(t_token **lst, t_token *token);

t_env		*make_envlist(char **env);
t_env		*env_createnew(char *s);
void		env_pushback(t_env **lst, t_env *new_node);
void		env_listclear(t_env **lst);
size_t		env_getcnt(t_env *lst);
int			is_target_env(char *str, char *env);
int			is_value_available(char *str);
int			is_valid_env_key(char *str, int is_unset);
char		*get_env_key(char *str);
char		*get_env_value(char *str);

void		handle_quote(t_info *info, t_token *token_list);
char		*handle_double_quote_with_env(t_info *info, char *s);
int			set_dollor_idx(char *s, int *dollor_idx, int *next_idx);
char		*find_value_in_env(t_env *env_list, char *s);

void		handle_env(t_info *info, t_token *token_list);

void		handle_seperator(t_token *token_list, char *sep);

ssize_t		ft_strcmp(char *src, char *dst);
void		p_list(t_env *list);
void		free_2d_str_array(char **arr);
void		four_times_free(char *s1, char *s2, char *s3, char *s4);

#endif
