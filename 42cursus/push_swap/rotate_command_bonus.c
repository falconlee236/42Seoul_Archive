/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:06 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/14 16:34:32 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_twodeque *deques)
{
	t_deque	*a;
	int		a_front;

	a = &(deques->a);
	if (is_empty(a))
		return ;
	a_front = get_front(a);
	pop_front(a);
	push_back(a, a_front);
}

void	rb(t_twodeque *deques)
{
	t_deque	*b;
	int		b_front;

	b = &(deques->b);
	if (is_empty(b))
		return ;
	b_front = get_front(b);
	pop_front(b);
	push_back(b, b_front);
}

void	rr(t_twodeque *deques)
{
	ra(deques);
	rb(deques);
}
