/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:57:41 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/21 21:47:10 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

typedef struct s_ppoint
{
	t_point	start;
	t_point	end;
}t_ppoint;

void	free_arr(char **arr);
int		ft_strlen_without_newline(char *s);
int		is_vaildmap(char *filename);
int		is_vaildpath(char **map, t_point point);
#endif