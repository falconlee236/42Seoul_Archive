/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaildpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:01:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/28 16:27:43 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft/ft_printf.h"

t_point	next_pos(t_point cur, int num)
{
	t_point	next;

	if (num == 0)
	{
		next.x = cur.x - 1;
		next.y = cur.y;
	}
	else if (num == 1)
	{
		next.x = cur.x;
		next.y = cur.y + 1;
	}
	else if (num == 2)
	{
		next.x = cur.x + 1;
		next.y = cur.y;
	}
	else
	{
		next.x = cur.x;
		next.y = cur.y - 1;
	}
	return (next);
}

void	dfs(char **map, int **visit, t_dfs_info *d_info, t_point point)
{
	int			i;
	t_point		next;

	i = 0;
	visit[point.x][point.y] = 1;
	if (map[point.x][point.y] == 'C')
		d_info->collect_cnt++;
	while (i < 4)
	{
		next = next_pos(point, i++);
		if (next.x < 0 || next.x >= d_info->size.x
			|| next.y < 0 || next.y >= d_info->size.y)
			continue ;
		if (map[next.x][next.y] != '1' && visit[next.x][next.y] != 1)
		{
			if (map[next.x][next.y] == 'E')
				d_info->exit_cnt += 1;
			else
				dfs(map, visit, d_info, next);
		}
	}
}

int	check_path(t_dfs_info dfs_info, t_info *info, int **visit)
{
	int	i;

	i = 0;
	if (info->collect_cnt == dfs_info.collect_cnt
		&& dfs_info.exit_cnt >= 1)
	{
		while (i < info->map_size.x)
			free(visit[i++]);
		free(visit);
		return (1);
	}
	return (0);
}

int	is_vaildpath(char **map, int **visit, t_point point, t_info *info)
{
	t_dfs_info	dfs_info;
	int			j;
	int			row;

	row = point.x;
	dfs_info.collect_cnt = 0;
	dfs_info.exit_cnt = 0;
	dfs_info.size = point;
	while (--row)
	{
		j = -1;
		while (++j < point.y)
		{
			if (map[row][j] == 'P')
			{
				dfs_info.start.x = row;
				dfs_info.start.y = j;
			}
		}
	}
	dfs(map, visit, &dfs_info, dfs_info.start);
	return (check_path(dfs_info, info, visit));
}
