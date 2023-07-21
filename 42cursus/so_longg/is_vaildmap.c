/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaildmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:57:28 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/21 21:55:02 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/get_next_line.h"
#include "./libft/ft_printf.h"

static char	**make_map(char *filename, int row_len)
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
	if (!map || !(*map))
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
		if (col_len != ft_strlen_without_newline(line))
		{
			ft_printf("asdfasdf\n");
			return (0);
		}
		line = get_next_line(fd);
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
	{
		free_arr(map);
		return (0);
	}
	return (1);
}

static int	is_config(char **map, int row, int col)
{
	int	exit;
	int	collect;
	int	start_pos;
	int	j;

	exit = 0;
	collect = 0;
	start_pos = 0;
	while (--row)
	{
		j = 0;
		while (j < col)
		{
			if (map[row][j] == 'C')
				collect++;
			else if (map[row][j] == 'E')
				exit++;
			else if (map[row][j] == 'P')
				start_pos++;
			j++;
		}
	}
	if (collect < 1 || exit != 1 || start_pos != 1)
		return (0);
	return (1);
}

int	is_vaildmap(char *filename)
{
	t_point	point;
	char	**map;
	int		**visit;

	if (ft_strlen(filename) < 5
		|| ft_strncmp(
			ft_substr(filename, ft_strlen(filename) - 4, 4), ".ber", 4))
		return (0);
	ft_printf("1111\n");
	point.x = is_rectangle(filename);
	if (point.x == 0)
		return (0);
	ft_printf("222\n");
	map = make_map(filename, point.x);
	point.y = ft_strlen(map[0]) - 1;
	if (!map || !is_surround(map, point.x, point.y))
		return (0);
	ft_printf("333\n");
	if (!is_config(map, point.x, point.y) || !is_vaildpath(map, point))
	{
		free_arr(map);
		return (0);
	}
	return (1);
}
