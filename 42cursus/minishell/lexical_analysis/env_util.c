/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:24:51 by yonyoo            #+#    #+#             */
/*   Updated: 2024/01/25 22:55:41 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analysis.h"

size_t	env_getcnt(t_env *lst)
{
	size_t	idx;

	idx = 0;
	while (lst)
	{
		lst = lst->next;
		idx++;
	}
	return (idx);
}

int	is_target_env(char *str, char *env)
{
	size_t	i;

	i = 0;
	while (str[i] && env[i] && str[i] != '=' && env[i] != '=')
	{
		if (str[i] != env[i])
			return (0);
		i++;
	}
	if (str[i] != '=' && str[i] && env[i] != '=' && env[i])
		return (0);
	return (1);
}

int	is_value_available(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

char	*get_env_key(char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	tmp[i] = '\0';
	j = 0;
	while (j < i)
	{
		tmp[j] = str[j];
		j++;
	}
	return (tmp);
}

char	*get_env_value(char *str)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	while (str && str[i] && str[i] != '=')
		i++;
	if (!str[i])
		return (NULL);
	size = -1;
	while (str[i + size])
		size++;
	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	tmp[size] = '\0';
	j = 0;
	while (j < size)
	{
		tmp[j] = str[i + j + 1];
		j++;
	}
	return (tmp);
}
