/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:18:17 by isang-yun         #+#    #+#             */
/*   Updated: 2024/02/06 15:02:49 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_exec.h"

static char	*check_env_value(char *input, int *start, int *end, t_info *info)
{
	(*end) = (*start) + 1;
	if (input[*end] == '?')
	{
		(*end) += 1;
		return (ft_itoa(info->status_code));
	}
	if (input[*end] == '\0' || !ft_isalnum(input[*end]))
		return (0);
	while (input[*end] && (ft_isalnum(input[*end]) || input[*end] == '_'))
		(*end)++;
	return (find_value_in_env(info->env_list,
			ft_substr(input, (*start) + 1, (*end) - (*start) - 1)));
}

static void	handle_env_in_heredoc(char *input, int fd, t_info *info)
{
	int		start;
	int		end;
	char	*env_value;

	start = 0;
	end = 0;
	while (input[end])
	{
		if (input[end] == '$')
		{
			write(fd, input + start, end - start);
			start = end;
			env_value = check_env_value(input, &start, &end, info);
			if (env_value)
			{
				write(fd, env_value, ft_strlen(env_value));
				free(env_value);
				start = end;
			}
		}
		else
			end++;
	}
	write(fd, input + start, end - start);
}

static void	create_tmpfile(char *file_name, char *delimiter, t_info *info)
{
	int		fd;
	char	*input;

	fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return ;
	signal(SIGINT, heredoc_handler);
	while (1)
	{
		input = readline("> ");
		if (!input)
			ft_putstr_fd("\033[1A\033[2C", STDERR_FILENO);
		if (!input || (ft_strncmp(input, delimiter, ft_strlen(input)) == 0
				&& ft_strlen(input) == ft_strlen(delimiter)))
		{
			close(fd);
			four_times_free(input, 0, 0, 0);
			return ;
		}
		handle_env_in_heredoc(input, fd, info);
		write(fd, "\n", 1);
		free(input);
	}
	close(fd);
	free(input);
}

void	exec_heredoc(t_cmd *cmd_list, t_info *info)
{
	int			file_cnt;
	char		*file_str;
	char		*file_name;
	t_redirect	*cur_redirect;

	file_cnt = 0;
	while (cmd_list)
	{
		cur_redirect = cmd_list->redirect;
		while (cur_redirect)
		{
			if (ft_strncmp(cur_redirect->type, "<<", 2) == 0
				&& ft_strlen(cur_redirect->type) == 2)
			{
				file_str = ft_itoa(file_cnt);
				file_name = ft_strjoin(file_str, ".tmp");
				create_tmpfile(file_name, cur_redirect->file, info);
				four_times_free(file_str, file_name, 0, 0);
			}
			cur_redirect = cur_redirect->next;
		}
		file_cnt++;
		cmd_list = cmd_list->next;
	}
	exit(0);
}

void	unlink_heredoc_tmp(t_cmd *cmd_list)
{
	char	*file_cnt;
	char	*file_name;
	int		cnt;

	cnt = 0;
	while (cmd_list)
	{
		file_cnt = ft_itoa(cnt);
		file_name = ft_strjoin(file_cnt, ".tmp");
		unlink(file_name);
		four_times_free(file_cnt, file_name, 0, 0);
		cmd_list = cmd_list->next;
		cnt++;
	}
}
