/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_function_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:04:59 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 15:04:53 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_deque *dq)
{
	if (dq->size == 0)
		return (1);
	else
		return (0);
}

int	get_front(t_deque *dq)
{
	return (dq->head->next->data);
}

int	get_back(t_deque *dq)
{
	return (dq->tail->prev->data);
}

int	twodeque_init(t_twodeque *deques)
{
	t_deque	*dq_a;
	t_deque	*dq_b;

	dq_a = &deques->a;
	dq_b = &deques->b;
	dq_a->size = 0;
	dq_b->size = 0;
	deques->cmd.size = 0;
	dq_a->head = make_newnode(-1);
	dq_a->tail = make_newnode(-1);
	dq_b->head = make_newnode(-1);
	dq_b->tail = make_newnode(-1);
	deques->cmd.head = make_newnode(-1);
	deques->cmd.tail = make_newnode(-1);
	if (!dq_a->head || !dq_a->tail || !dq_b->head || !dq_b->tail
		|| !(deques->cmd.head) || !(deques->cmd.tail))
		return (0);
	dq_a->head->next = dq_a->tail;
	dq_a->tail->prev = dq_a->head;
	dq_b->head->next = dq_b->tail;
	dq_b->tail->prev = dq_b->head;
	deques->cmd.head->next = deques->cmd.tail;
	deques->cmd.tail->prev = deques->cmd.head;
	return (1);
}
