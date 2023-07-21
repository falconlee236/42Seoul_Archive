/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_command_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:06 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/14 16:34:45 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	rrr(t_twodeque *deques)
{
	rra(deques);
	rrb(deques);
}
