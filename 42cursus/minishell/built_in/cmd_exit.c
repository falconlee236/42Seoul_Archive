/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:06:32 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 14:57:58 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	is_numeric_only(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static void	check_arg(char **argv, int *arg_cnt,
	int *arg_code, int *is_numeric_err)
{
	*arg_cnt = 1;
	*is_numeric_err = 0;
	while (argv && argv[*arg_cnt])
	{
		if (!is_numeric_only(argv[*arg_cnt]))
			*is_numeric_err = 1;
		(*arg_cnt)++;
	}
	if (argv && argv[1])
		*arg_code = ft_atoi(argv[1]);
}

int	cmd_exit(char **argv, t_cmd *cmd_list)
{
	int	arg_cnt;
	int	arg_code;
	int	is_numeric_err;

	check_arg(argv, &arg_cnt, &arg_code, &is_numeric_err);
	unlink_heredoc_tmp(cmd_list);
	if (arg_cnt > 2)
	{
		ft_putendl_fd("pmshell: exit: too many arguments", 2);
		return (1);
	}
	if (is_numeric_err)
	{
		ft_putstr_fd("pmshell: exit: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	if (arg_cnt == 2)
		exit(arg_code);
	exit(0);
	return (0);
}
