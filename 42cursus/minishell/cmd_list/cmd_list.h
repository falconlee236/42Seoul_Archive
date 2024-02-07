/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:34:28 by yonyoo            #+#    #+#             */
/*   Updated: 2024/01/21 16:49:29 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_LIST_H
# define CMD_LIST_H
# include "../pm_shell.h"

typedef struct s_token	t_token;

typedef struct s_redirect
{
	char					*type;
	char					*file;
	struct s_redirect		*next;
}	t_redirect;

typedef struct s_cmd
{
	char			**argv;
	t_redirect		*redirect;
	int				pipe[2];
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

t_cmd		*make_cmdlist(t_token *token_list);

void		cmd_listclear(t_cmd **lst);
t_cmd		*cmd_createnew(void);
t_cmd		*cmd_pushback(t_cmd **lst, t_cmd *new_node);

t_redirect	*redirect_createnew(char *file, char *type);
void		redirect_pushback(t_redirect **lst, t_redirect *new_node);
void		redirect_listclear(t_redirect **lst);

#endif
