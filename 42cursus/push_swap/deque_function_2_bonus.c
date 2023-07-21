/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_function_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:53:07 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/14 16:35:11 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_node	*make_newnode(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = data;
	node->next = 0;
	node->prev = 0;
	return (node);
}

void	pop_front(t_deque *dq)
{
	int		data;
	t_node	*d_node;

	if (dq->size == 0)
		return ;
	d_node = dq->head->next;
	data = d_node->data;
	dq->head->next = dq->head->next->next;
	dq->head->next->prev = dq->head;
	free(d_node);
	(dq->size)--;
}

void	pop_back(t_deque *dq)
{
	int		data;
	t_node	*d_node;

	if (dq->size == 0)
		return ;
	d_node = dq->tail->prev;
	data = d_node->data;
	dq->tail->prev = dq->tail->prev->prev;
	dq->tail->prev->next = dq->tail;
	free(d_node);
	(dq->size)--;
}

void	push_back(t_deque *dq, int data)
{
	t_node	*node;

	node = make_newnode(data);
	if (!node)
		return ;
	dq->tail->prev->next = node;
	node->prev = dq->tail->prev;
	dq->tail->prev = node;
	node->next = dq->tail;
	(dq->size)++;
}

void	push_front(t_deque *dq, int data)
{
	t_node	*node;

	node = make_newnode(data);
	if (!node)
		return ;
	dq->head->next->prev = node;
	node->next = dq->head->next;
	dq->head->next = node;
	node->prev = dq->head;
	(dq->size)++;
}
