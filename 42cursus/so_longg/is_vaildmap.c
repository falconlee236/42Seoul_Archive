/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaildmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:57:28 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/28 19:28:28 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/get_next_line.h"

static char	**make_map(char *filename, int row_len)
{
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
	map[i++] = get_next_line(fd);
	while (i < row_len)
		map[i++] = get_next_line(fd);
	map[i] = 0;
	close(fd);
	return (map);
}

static int	is_rectangle(char *filename)
{
	char	*line;
	int		col_len;
	int		row_len;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	col_len = ft_strlen_without_newline(line);
	row_len = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line && col_len != ft_strlen_without_newline(line))
		{
			free(line);
			return (close(fd));
		}
		row_len++;
	}
	close(fd);
	return (row_len);
}

static int	is_surround(char **map, int row, int col)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < row)
	{
		if (map[i][0] != '1' || map[i][col - 1] != '1')
			flag = 0;
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (map[0][i] != '1' || map[row - 1][i] != '1')
			flag = 0;
		i++;
	}
	if (!flag)
		return (0);
	return (1);
}

static int	is_config(char **map, int row, int col, t_info *info)
{
	int	exit_num;
	int	start_num;
	int	i;
	int	j;

	exit_num = 0;
	start_num = 0;
	i = -1;
	while (++i < row)
	{
		j = -1;
		while (++j < col)
		{
			if (map[i][j] == 'C')
				info->collect_cnt++;
			else if (map[i][j] == 'E')
				exit_num++;
			else if (map[i][j] == 'P')
				start_num++;
		}
	}
	if (info->collect_cnt < 1 || exit_num != 1 || start_num != 1)
		return (0);
	return (1);
}

int	is_vaildmap(char *filename, t_info *info)
{
	int		**visit;
	char	*substr;

	substr = ft_substr(filename, ft_strlen(filename) - 4, 4);
	if (ft_strlen(filename) < 5 || ft_strncmp(substr, ".ber", 4))
		return (free_return(substr));
	info->map_size.x = is_rectangle(filename);
	if (info->map_size.x == 0)
		return (0);
	info->map = make_map(filename, info->map_size.x);
	info->map_size.y = ft_strlen_without_newline(info->map[0]);
	visit = make_visit_arr(info->map_size.x, info->map_size.y);
	if (!visit
		|| !is_config(info->map, info->map_size.x, info->map_size.y, info)
		|| !is_surround(info->map, info->map_size.x, info->map_size.y)
		|| !is_vaildpath(info->map, visit, info->map_size, info))
	{
		free_arr(info->map);
		free(info->mlx);
		free(info->win);
		return (free_return(substr));
	}
	free(substr);
	return (1);
}
