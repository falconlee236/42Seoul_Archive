/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pm_shell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:37:39 by sangylee          #+#    #+#             */
/*   Updated: 2024/02/06 15:25:15 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PM_SHELL_H
# define PM_SHELL_H
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include "built_in/built_in.h"
# include "cmd_exec/cmd_exec.h"
# include "cmd_list/cmd_list.h"
# include "lexical_analysis/lexical_analysis.h"
# include "libft/libft.h"
# include "sig_handle/sig_handle.h"
# include "syntax_analysis/syntax_analysis.h"

int	g_signo;

typedef struct s_env{
	char			*str;
	struct s_env	*next;
}t_env;

typedef struct s_info
{
	t_env	*env_list;
	int		is_error;
	int		status_code;
	int		stdin_fd;
	int		stdout_fd;
	int		tmp_cnt;
}t_info;

char	**get_env_str_list(t_env *env_list);
char	**get_path_env(t_env *env_list);
int		check_input(char *input, t_info *info, struct termios *term);
int		syntax_error_cleanup(t_info *info, t_token *token_list);
void	init_info(t_info *info, int argc, char **argv, char **env);
void	init_termios(void);
void	print_argument_err(char *str);
void	update_env(char **str, char *new);
void	make_exec_cmd_list(t_cmd **cmd_list, t_info *info,
			t_token *token_list);

#endif
