/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:23:20 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 15:24:39 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pm_shell.h"

void	init_termios(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	init_info(t_info *info, int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	info->env_list = make_envlist(env);
	info->is_error = 0;
	info->status_code = 0;
	info->stdin_fd = dup(STDIN_FILENO);
	info->stdout_fd = dup(STDOUT_FILENO);
	init_sig_handler();
	init_termios();
}

int	check_input(char *input, t_info *info, struct termios *term)
{
	char	*tmp;

	info->tmp_cnt = 0;
	if (g_signo == SIGINT)
		info->status_code = 1;
	g_signo = 0;
	if (!input)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		tcsetattr(STDIN_FILENO, TCSANOW, term);
		exit(1);
	}
	tmp = ft_strtrim(input, " ");
	if (ft_strlen(input) == 1 && input[0] != ' ')
	{
		free(tmp);
		return (0);
	}
	if (tmp[0] == '\0')
	{
		four_times_free(tmp, input, 0, 0);
		return (1);
	}
	free(tmp);
	return (0);
}

void	make_exec_cmd_list(t_cmd **cmd_list, t_info *info,
	t_token *token_list)
{
	*cmd_list = make_cmdlist(token_list);
	exec_cmd_list(*cmd_list, info);
	token_listclear(&token_list);
	cmd_listclear(cmd_list);
}

int	syntax_error_cleanup(t_info *info, t_token *token_list)
{
	ft_putstr_fd("pm_shell: invalid syntax\n", STDERR_FILENO);
	info->status_code = 258;
	token_listclear(&token_list);
	return (1);
}
