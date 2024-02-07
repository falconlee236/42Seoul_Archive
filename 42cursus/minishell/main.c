/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:02:04 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 15:23:36 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pm_shell.h"

int	main(int argc, char **argv, char **env)
{
	char			*input;
	t_info			info;
	t_token			*token_list;
	t_cmd			*cmd_list;
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	init_info(&info, argc, argv, env);
	while (!info.is_error)
	{
		input = readline("pmshell> :$ ");
		if (check_input(input, &info, &term))
			continue ;
		token_list = lexical_analysis(&info, input);
		if (!syntax_analysis(token_list)
			&& syntax_error_cleanup(&info, token_list))
			continue ;
		make_exec_cmd_list(&cmd_list, &info, token_list);
	}
	env_listclear(&(info.env_list));
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	return (0);
}
