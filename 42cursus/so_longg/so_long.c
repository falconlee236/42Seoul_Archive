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

int	main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	if (ac != 2 || !is_vaildmap(av[1]))
	{
		ft_printf("Argument Error\n");
		return (0);
	}
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	mlx_loop(mlx_ptr);
}
