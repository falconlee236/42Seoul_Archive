/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_longutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 18:11:29 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/01 16:46:47 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_enemy_set(t_info *info)
{
	info->enemy_img_set[0] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy00.xpm", &info->img_size.x, &info->img_size.y);
	info->enemy_img_set[1] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy01.xpm", &info->img_size.x, &info->img_size.y);
	info->enemy_img_set[2] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy02.xpm", &info->img_size.x, &info->img_size.y);
	info->enemy_img_set[3] = mlx_xpm_file_to_image(info->mlx,
			"assets/enemy03.xpm", &info->img_size.x, &info->img_size.y);
	info->enemy_img = info->enemy_img_set[0];
	if (!info->enemy_img_set[0] || !info->enemy_img_set[1]
		|| !info->enemy_img_set[2] || !info->enemy_img_set[3])
		return (0);
	return (1);
}

int	info_init(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, 2400, 900, "so_long");
	info->collect_cnt = 0;
	info->enemy_cnt = 0;
	info->walk_cnt = 0;
	info->wall_img = mlx_xpm_file_to_image(info->mlx,
			"assets/wall.xpm", &info->img_size.x, &info->img_size.y);
	info->collect_img = mlx_xpm_file_to_image(info->mlx,
			"assets/collector.xpm", &info->img_size.x, &info->img_size.y);
	info->field_img = mlx_xpm_file_to_image(info->mlx,
			"assets/background.xpm", &info->img_size.x, &info->img_size.y);
	info->player_img = mlx_xpm_file_to_image(info->mlx,
			"assets/player.xpm", &info->img_size.x, &info->img_size.y);
	info->exit_img = mlx_xpm_file_to_image(info->mlx,
			"assets/exit.xpm", &info->img_size.x, &info->img_size.y);
	if (!info->mlx || !info->win || !info->wall_img || !info->collect_img
		|| !info->field_img || !info->player_img
		|| !info->exit_img || !init_enemy_set(info))
		return (0);
	return (1);
}

void	draw_map(t_info *info, int i, int j)
{
	while (++i < info->map_size.x)
	{
		j = -1;
		while (++j < info->map_size.y)
		{
			mlx_put_image_to_window(info->mlx, info->win, info->field_img,
				j * info->img_size.x, i * info->img_size.y);
			if (info->map[i][j] == 'E')
				mlx_put_image_to_window(info->mlx, info->win, info->exit_img,
					j * info->img_size.x, i * info->img_size.y);
			else if (info->map[i][j] == 'X')
				mlx_put_image_to_window(info->mlx, info->win, info->enemy_img,
					j * info->img_size.x, i * info->img_size.y);
			else if (info->map[i][j] == '1')
				mlx_put_image_to_window(info->mlx, info->win, info->wall_img,
					j * info->img_size.x, i * info->img_size.y);
			else if (info->map[i][j] == 'C')
				mlx_put_image_to_window(info->mlx, info->win, info->collect_img,
					j * info->img_size.x, i * info->img_size.y);
			else if (info->map[i][j] == 'P')
				mlx_put_image_to_window(info->mlx, info->win, info->player_img,
					j * info->img_size.x, i * info->img_size.y);
		}
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	put_string_in_window(t_info *info, int cnt)
{
	char	*cnt_str;
	char	*base_str;
	char	*res;

	cnt_str = ft_itoa(cnt);
	if (!cnt_str)
		return (0);
	base_str = ft_strdup("walk_cnt ");
	if (!base_str)
	{
		free(cnt_str);
		return (0);
	}
	res = ft_strjoin(base_str, cnt_str);
	if (!res)
	{
		free(cnt_str);
		free(base_str);
		return (0);
	}
	mlx_string_put(info->mlx, info->win, 10, 10, create_trgb(0, 0, 0, 0), res);
	free(cnt_str);
	free(base_str);
	free(res);
	return (1);
}
