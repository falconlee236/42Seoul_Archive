/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:38:20 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 16:05:47 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			*arr;
	int			i;
	t_twodeque	deques;

	if (argc < 2)
		return (0);
	arr = check_arg(argc - 1, argv + 1);
	if (!arr)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (indexing(arr, argc - 1))
		return (0);
	twodeque_init(&deques);
	i = 0;
	while (i < argc - 1)
		push_back(&deques.a, arr[i++]);
	if (argc - 1 < 6)
		small_number(argc - 1, &deques);
	else
		sand_clock_algo(argc - 1, &deques);
	free(arr);
}
