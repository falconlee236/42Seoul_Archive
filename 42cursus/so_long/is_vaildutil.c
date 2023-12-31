/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaildutil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:38:02 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/04 15:28:17 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !(*arr))
		return (0);
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

int	**make_visit_arr(int row, int col)
{
	int	**arr;
	int	i;
	int	j;
	int	k;

	arr = (int **)malloc(sizeof(int *) * row);
	i = 0;
	j = 0;
	if (!arr)
		return (0);
	while (i < row)
	{
		arr[i] = (int *)malloc(sizeof(int) * col);
		k = 0;
		while (k < col)
			arr[i][k++] = 0;
		if (!arr[i++])
		{
			while (j <= i)
				free(arr[j++]);
			free(arr);
			return (0);
		}
	}
	return (arr);
}

int	ft_strlen_without_newline(char *s)
{
	int	len;
	int	num;

	len = 0;
	num = -1;
	if (!s)
		return (0);
	while (s[len])
	{
		if (s[len] == '\n')
			num = len;
		len++;
	}
	len = 0;
	while (s[len])
		len++;
	if (num == -1)
		return (len);
	else
		return (len - 1);
}

int	free_return(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (0);
}

void	free_visit_arr(int **visit, int row)
{
	int	i;

	i = 0;
	if (!visit)
		return ;
	while (i < row)
	{
		free(visit[i]);
		i++;
	}
	free(visit);
	return ;
}
