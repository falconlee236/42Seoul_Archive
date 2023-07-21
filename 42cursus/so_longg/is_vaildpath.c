/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vaildpath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 15:01:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/21 21:51:43 by sangylee         ###   ########.fr       */
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

void	dfs(char **map, t_ppoint p, t_point point)
{
	int			i;
	t_ppoint	nt;

	i = 0;
	nt.end = p.end;
	ft_printf("%d %d\n", p.start.x, p.start.y);
	if (p.start.x == p.end.x && p.start.y == p.end.y)
	{
		map[0][0] = '!';
		return ;
	}
	while (i < 4)
	{
		nt.start = next_pos(p.start, i++);
		if (nt.start.x < 0 || nt.start.x >= point.x || nt.start.y < 0
			|| nt.start.y >= point.y)
			continue ;
		if (!(map[nt.start.x][nt.start.y] == '1'
			|| map[nt.start.x][nt.start.y] == '*'))
		{
			map[nt.start.x][nt.start.y] = 1;
			dfs(map, nt, point);
			map[nt.start.x][nt.start.y] = 0;
		}
	}
}

int	check_path(char **map)
{
	if (map[0][0] == '!')
	{
		map[0][0] = '1';
		return (1);
	}
	return (0);
}

int	is_vaildpath(char **map, t_point point)
{
	t_ppoint	start_end;
	int			j;
	int			row;

	row = point.x;
	while (--row)
	{
		j = -1;
		while (++j < point.y)
		{
			if (map[row][j] == 'P')
			{
				start_end.start.x = row;
				start_end.start.y = j;
			}
			else if (map[row][j] == 'E')
			{
				start_end.end.x = row;
				start_end.end.y = j;
			}
		}
	}
	dfs(map, start_end, point);
	return (check_path(map));
}
