/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:57:41 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/01 14:42:57 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define ON_DESTROY 				17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_dfs_info
{
	int		collect_cnt;
	int		exit_cnt;
	t_point	start;
	t_point	size;
}t_dfs_info;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	void	*field_img;
	void	*wall_img;
	void	*collect_img;
	void	*exit_img;
	void	*player_img;
	void	*enemy_img;
	void	*enemy_img_set[4];
	int		collect_cnt;
	int		enemy_cnt;
	int		walk_cnt;
	char	**map;
	t_point	map_size;
	t_point	img_size;
	t_point	s_pos;
	t_point	e_pos;
	t_point	pos;
}t_info;

int		free_arr(char **arr);
void	free_visit_arr(int **visit, int row);
int		free_return(char *str);
int		ft_strlen_without_newline(char *s);

int		is_vaildpath(char **map, int **visit, t_point point, t_info *info);
int		**make_visit_arr(int row, int col);
int		is_vaildmap(char *filename, t_info *info);
void	make_enemy(char **map, int row, int col, t_info *info);

int		info_init(t_info *info);
void	draw_map(t_info *info, int i, int j);
int		create_trgb(int t, int r, int g, int b);
int		put_string_in_window(t_info *info, int cnt);

int		key_hook_event(int keycode, t_info *info);
int		destory_hook_event(t_info *info);

int		loop_hook_event(t_info *info);
#endif