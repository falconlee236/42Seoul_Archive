/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:46:09 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 18:52:16 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	is_num(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (len == 0)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (i == len)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(int cnt, int *arr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < cnt)
	{
		while (j < cnt)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	*check_arg(int cnt, char **input)
{
	int			*res;
	int			i;
	long long	num;

	res = (int *)malloc(sizeof(int) * cnt);
	i = 0;
	while (i < cnt)
	{
		num = ft_atoll(input[i]);
		if (num > 2147483647LL || num < -2147483648LL || !is_num(input[i]))
		{
			free(res);
			return (0);
		}
		res[i] = (int)num;
		i++;
	}
	if (!is_duplicate(cnt, res))
	{
		free(res);
		return (0);
	}
	return (res);
}
