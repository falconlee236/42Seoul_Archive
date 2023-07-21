/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:06 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/17 13:12:45 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

void	rra(t_twodeque *deques)
{
	t_deque	*a;
	int		a_back;

	a = &(deques->a);
	if (is_empty(a))
		return ;
	a_back = get_back(a);
	pop_back(a);
	push_front(a, a_back);
	ft_printf("rra\n");
	push_back(&(deques->cmd), 8);
	return ;
}

void	rrb(t_twodeque *deques)
{
	t_deque	*b;
	int		b_back;

	b = &(deques->b);
	if (is_empty(b))
		return ;
	b_back = get_back(b);
	pop_back(b);
	push_front(b, b_back);
	ft_printf("rrb\n");
	push_back(&(deques->cmd), 9);
	return ;
}

void	rrr(t_twodeque *deques)
{
	rra(deques);
	rrb(deques);
	ft_printf("rrr\n");
	push_back(&(deques->cmd), 10);
	return ;
}
