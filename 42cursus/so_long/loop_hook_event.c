/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:34:14 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/01 18:33:23 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <time.h>
#include <stdlib.h>

void	next_enemy_pos(int *next_x, int *next_y, int x, int y)
{
	int	num;

	num = rand();
	if (num % 4 == 0)
	{
		*next_x = x;
		*next_y = y - 1;
	}
	else if (num % 4 == 1)
	{
		*next_x = x + 1;
		*next_y = y;
	}
	else if (num % 4 == 2)
	{
		*next_x = x;
		*next_y = y + 1;
	}
	else if (num % 4 == 3)
	{
		*next_x = x - 1;
		*next_y = y;
	}
}

static void	patrol_enemy(t_info *info, int x, int y, int cnt)
{
	int	next_x;
	int	next_y;

	if (cnt % 50 != 0)
		return ;
	next_x = 0;
	next_y = 0;
	next_enemy_pos(&next_x, &next_y, x, y);
	if (next_y < 0 || next_y >= info->map_size.y
		|| next_x < 0 || next_x >= info->map_size.x
		|| info->map[next_x][next_y] == '1' || info->map[next_x][next_y] == 'E'
		|| info->map[next_x][next_y] == 'C')
		return ;
	if (info->map[next_x][next_y] == 'P')
		exit(1);
	info->map[next_x][next_y] = 'X';
	info->map[x][y] = '0';
}

int	loop_hook_event(t_info *info)
{
	int			i;
	int			j;
	static int	cnt;

	i = 0;
	cnt++;
	srand(time(NULL));
	info->enemy_img = info->enemy_img_set[(cnt / 20) % 4];
	while (i < info->map_size.x)
	{
		j = 0;
		while (j < info->map_size.y)
		{
			if (info->map[i][j] == 'X')
				patrol_enemy(info, i, j, cnt);
			j++;
		}
		i++;
	}
	draw_map(info, -1, -1);
	if (!put_string_in_window(info, info->walk_cnt))
		return (0);
	return (1);
}
