/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-shift_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:02:06 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/17 13:10:21 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

void	sa(t_twodeque *deques)
{
	t_deque	a;
	t_node	*first;
	t_node	*second;

	a = deques->a;
	if (is_empty(&a) || a.size == 1)
		return ;
	first = a.head->next;
	second = a.head->next->next;
	first->next = second->next;
	first->prev = second;
	first->next->prev = first;
	a.head->next = second;
	second->prev = a.head;
	second->next = first;
	ft_printf("sa\n");
	push_back(&(deques->cmd), 0);
	return ;
}

void	sb(t_twodeque *deques)
{
	t_deque	b;
	t_node	*first;
	t_node	*second;

	b = deques->b;
	if (is_empty(&b) || b.size == 1)
		return ;
	first = b.head->next;
	second = b.head->next->next;
	first->next = second->next;
	first->prev = second;
	first->next->prev = first;
	b.head->next = second;
	second->prev = b.head;
	second->next = first;
	ft_printf("sb\n");
	push_back(&(deques->cmd), 1);
	return ;
}

void	ss(t_twodeque *deques)
{
	sa(deques);
	sb(deques);
	ft_printf("ss\n");
	push_back(&(deques->cmd), 2);
	return ;
}

void	pa(t_twodeque *deques)
{
	t_deque	*a;
	t_deque	*b;
	int		b_front;

	a = &(deques->a);
	b = &(deques->b);
	if (is_empty(b))
		return ;
	b_front = get_front(b);
	pop_front(b);
	push_front(a, b_front);
	ft_printf("pa\n");
	push_back(&(deques->cmd), 3);
	return ;
}

void	pb(t_twodeque *deques)
{
	t_deque	*a;
	t_deque	*b;
	int		a_front;

	a = &(deques->a);
	b = &(deques->b);
	if (is_empty(a))
		return ;
	a_front = get_front(a);
	pop_front(a);
	push_front(b, a_front);
	ft_printf("pb\n");
	push_back(&(deques->cmd), 4);
	return ;
}
