/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:36 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/04 15:23:43 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info	info;

	info.collect_cnt = 0;
	info.enemy_cnt = 0;
	info.walk_cnt = 0;
	if (ac != 2 || !is_vaildmap(av[1], &info))
		return (write(2, "Error\n Argument", 15));
	if (!info_init(&info))
	{
		free_arr(info.map);
		return (write(2, "Error\n init", 11));
	}
	make_enemy(info.map, info.map_size.x, info.map_size.y, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_hook_event, &info);
	mlx_hook(info.win, ON_DESTROY, 0, &destory_hook_event, &info);
	mlx_loop_hook(info.mlx, &loop_hook_event, &info);
	mlx_loop(info.mlx);
}
