/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:14:38 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/01 18:33:38 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/ft_printf.h"

static int	key_event_process(t_info *info, t_point tp)
{
	if (info->map[tp.x][tp.y] == 'C')
		info->collect_cnt--;
	else if (info->map[tp.x][tp.y] == 'X')
	{
		mlx_destroy_window(info->mlx, info->win);
		return (ft_printf("You lose!\n"));
	}
	else if (info->map[tp.x][tp.y] == 'E')
	{
		if (info->collect_cnt == 0)
		{
			mlx_destroy_window(info->mlx, info->win);
			return (ft_printf("You Win!!\n"));
		}
		else
			return (0);
	}
	info->map[tp.x][tp.y] = 'P';
	info->map[info->pos.x][info->pos.y] = '0';
	mlx_clear_window(info->mlx, info->win);
	draw_map(info, -1, -1);
	if (!put_string_in_window(info, ++(info->walk_cnt)))
		return (0);
	info->pos = tp;
	return (ft_printf("walk count %d\n", info->walk_cnt));
}

int	destory_hook_event(t_info *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(1);
}

int	key_hook_event(int keycode, t_info *info)
{
	t_point	tp;

	tp = info->pos;
	if (keycode == KEY_ESC)
		return (destory_hook_event(info));
	else if (keycode == KEY_A)
		tp = (t_point){.x = info->pos.x, .y = info->pos.y - 1};
	else if (keycode == KEY_S)
		tp = (t_point){.x = info->pos.x + 1, .y = info->pos.y};
	else if (keycode == KEY_D)
		tp = (t_point){.x = info->pos.x, .y = info->pos.y + 1};
	else if (keycode == KEY_W)
		tp = (t_point){.x = info->pos.x - 1, .y = info->pos.y};
	else
		return (0);
	if (tp.x < 0 || tp.x >= info->map_size.x || tp.y < 0
		|| tp.y >= info->map_size.y || info->map[tp.x][tp.y] == '1')
		return (0);
	if (key_event_process(info, tp) == 10)
	{
		free_arr(info->map);
		exit(1);
	}
	return (1);
}
