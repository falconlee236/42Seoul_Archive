/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:38:02 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/21 18:24:22 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_strlen_without_newline(char *s)
{
	int	len;
	int	num;

	len = 0;
	num = -1;
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
