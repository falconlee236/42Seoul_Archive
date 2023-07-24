/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:49:36 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/21 17:18:25 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx/mlx.h"
#include "so_long.h"
#include "./libft/ft_printf.h"
#include "./libft/get_next_line.h"
#include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2


char	**make_map(char *filename, int row_len)
{
    char	*line;
    int		fd;
    int		i;
    char	**map;

    fd = open(filename, O_RDONLY);
    map = (char **)malloc(sizeof(char *) * (row_len + 1));
    i = 0;
    if (fd < 0)
        return (0);
    if (!map)
    {
        free_arr(map);
        return (0);
    }
    line = get_next_line(fd);
    map[i++] = line;
    while (i < row_len)
        map[i++] = get_next_line(fd);
    map[i] = 0;
    close(fd);
    return (map);
}

void (int keycode, int *x, int *y)
{
    int next_x = *x, next_y = *y;
    if (keycode == KEY_W)
        next_x--;
    else if (keycode == KEY_A)
        next_y--;
    else if (keycode == KEY_S)
        next_x++;
    else if (keycode == KEY_S)
        next_y++;
    if (next_x < 0 || next_x >= )
}

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2 ){
		ft_printf("Argument Error\n");
		return (0);
	}
    int row = 6, col = 34;
    char **map = make_map(av[1], row);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    int win_height = 900, win_width = 1800;
    int img_width = 48, img_height = 48;
	mlx_ptr = mlx_init();
// 가로 50cm 세로 25cm 기준 50 -> 1889pixel, 944 pixel 그러면 우리는 화면 크기를 1800 * 900으로 하고 비율을 조정해야할듯
	win_ptr = mlx_new_window(mlx_ptr, win_width, win_height, "mlx 42");
    void *back = mlx_xpm_file_to_image(mlx_ptr, "assets/background.xpm", &img_width, &img_height);
    void *exit = mlx_xpm_file_to_image(mlx_ptr, "assets/exit.xpm", &img_width, &img_height);
    void *enemy = mlx_xpm_file_to_image(mlx_ptr, "assets/enemy.xpm", &img_width, &img_height);
    void *collect = mlx_xpm_file_to_image(mlx_ptr, "assets/collector.xpm", &img_width, &img_height);
    void *player = mlx_xpm_file_to_image(mlx_ptr, "assets/player.xpm", &img_width, &img_height);
    void *wall = mlx_xpm_file_to_image(mlx_ptr, "assets/wall.xpm", &img_width, &img_height);

    int i = 0;
    while (i < row)
    {
        int j = 0;
        while (j < col)
        {
            mlx_put_image_to_window(mlx_ptr, win_ptr, back, j * img_height, i * img_width);
            if (map[i][j] == 'E')
                mlx_put_image_to_window(mlx_ptr, win_ptr, exit, j * img_height, i * img_width);
            else if (map[i][j] == 'X')
                mlx_put_image_to_window(mlx_ptr, win_ptr, enemy, j * img_height, i * img_width);
            else if (map[i][j] == '1')
                mlx_put_image_to_window(mlx_ptr, win_ptr, wall, j * img_height, i * img_width);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(mlx_ptr, win_ptr, collect, j * img_height, i * img_width);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(mlx_ptr, win_ptr, player, j * img_height, i * img_width);
            j++;
        }
        i++;
    }
    int x = 4, y = 1;


    //이제 해야할 것.
    /*
     * 1. 화면 비율 맞추기
     * 2. wasd로 캐릭터 움직이는것 만들기
     * 3. 캐릭터 움직이는 것을 터미널에 출력하기
     * 4. 캐릭터가 수집품에 닿으면 먹는 것 구현하기
     * 5.
     */
	mlx_loop(mlx_ptr);
}
