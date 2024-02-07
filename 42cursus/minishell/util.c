/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 21:58:39 by isang-yun         #+#    #+#             */
/*   Updated: 2024/01/26 01:31:53 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pm_shell.h"

ssize_t	ft_strcmp(char *src, char *dst)
{
	ssize_t	i;

	i = 0;
	while (src[i] && dst[i] && src[i] == dst[i])
		i++;
	return (src[i] - dst[i]);
}

void	p_list(t_env *list)
{
	while (list)
	{
		printf("%s\n", list->str);
		list = list->next;
	}
	printf("-----------------\n");
}

void	free_2d_str_array(char **arr)
{
	int	i;

	i = -1;
	if (!arr)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	four_times_free(char *s1, char *s2, char *s3, char *s4)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (s3)
		free(s3);
	if (s4)
		free(s4);
}

int	is_valid_env_key(char *str, int is_unset)
{
	size_t	i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (!is_unset);
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}
