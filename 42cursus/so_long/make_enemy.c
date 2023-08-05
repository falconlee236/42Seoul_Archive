/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:20:56 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/04 13:57:37 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_pos(char **map, int row, int col, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == 'E')
			{
				info->e_pos.x = i;
				info->e_pos.y = j;
			}
			else if (map[i][j] == 'P')
			{
				info->s_pos.x = i;
				info->s_pos.y = j;
			}
			j++;
		}
		i++;
	}
}

static int	count_empty(char **map, int row, int col)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (map[i][j] == '0')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

void	make_enemy(char **map, int row, int col, t_info *info)
{
	int	rand_num;
	int	i;
	int	std;

	i = 0;
	srand(time(NULL));
	if (count_empty(map, row, col) < 5)
		std = 0;
	else
		std = 4;
	while (i < std)
	{
		rand_num = rand() % (row * col);
		while (map[rand_num / col][rand_num % col] != '0')
			rand_num = rand() % (row * col);
		map[rand_num / col][rand_num % col] = 'X';
		i++;
		info->enemy_cnt++;
	}
	set_pos(map, row, col, info);
	info->pos = info->s_pos;
}
