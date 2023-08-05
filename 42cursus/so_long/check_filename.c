/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:09:33 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/04 14:56:04 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filename(void)
{
	if (open("assets/wall.xpm", O_RDONLY) < 0
		|| open("assets/collector.xpm", O_RDONLY) < 0
		|| open("assets/background.xpm", O_RDONLY) < 0
		|| open("assets/player.xpm", O_RDONLY) < 0
		|| open("assets/exit.xpm", O_RDONLY) < 0
		|| open("assets/enemy00.xpm", O_RDONLY) < 0
		|| open("assets/enemy01.xpm", O_RDONLY) < 0
		|| open("assets/enemy02.xpm", O_RDONLY) < 0
		|| open("assets/enemy03.xpm", O_RDONLY) < 0)
		return (0);
	return (1);
}
