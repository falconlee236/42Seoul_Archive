/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:36 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/01 18:39:38 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	leak_check(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_info	info;

	atexit(leak_check);
	if (!info_init(&info))
		return (write(2, "Error\n init", 10));
	if (ac != 2 || !is_vaildmap(av[1], &info))
	{
		return (write(2, "Error\n Argument", 15));
	}
	make_enemy(info.map, info.map_size.x, info.map_size.y, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_hook_event, &info);
	mlx_hook(info.win, ON_DESTROY, 0, &destory_hook_event, &info);
<<<<<<< HEAD:42cursus/so_long/so_long.c
	mlx_loop_hook(info.mlx, &loop_hook_event, &info);
=======
	// mlx_loop_hook(info.mlx, )

>>>>>>> 76de1ea514acb367c6bec1463b19c2d5592319ec:42cursus/so_longg/so_long.c
	mlx_loop(info.mlx);
}
