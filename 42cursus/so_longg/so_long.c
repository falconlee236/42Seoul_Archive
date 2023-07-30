/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:36 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/28 20:05:31 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_info	info;

	if (!info_init(&info))
	{
		system("leaks so_long");
		return (write(2, "init Error\n", 10));
	}
	if (ac != 2 || !is_vaildmap(av[1], &info))
	{
		system("leaks so_long");
		return (write(2, "Argument Error\n", 15));
	}
	make_enemy(info.map, info.map_size.x, info.map_size.y, &info);
	draw_map(&info, -1, -1);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_hook_event, &info);
	mlx_hook(info.win, ON_DESTROY, 0, &destory_hook_event, &info);
	// mlx_loop_hook(info.mlx, )
	mlx_loop(info.mlx);
}
