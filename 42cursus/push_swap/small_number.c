/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:26:22 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 14:28:38 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/ft_printf.h"

void	sort_three_case(t_twodeque *deques, int a, int b, int c)
{
	if (a < b && b < c && a < c)
		return ;
	else if (a < b && b > c && a < c)
	{
		pb(deques);
		sa(deques);
		pa(deques);
	}
	else if (a > b && b < c && a < c)
		sa(deques);
	else if (a < b && b > c && a > c)
		rra(deques);
	else if (a > b && b < c && a > c)
		ra(deques);
	else
	{
		sa(deques);
		rra(deques);
	}
}

void	sort_three(t_twodeque *deques)
{
	int	a;
	int	b;
	int	c;

	a = deques->a.head->next->data;
	b = deques->a.head->next->next->data;
	c = deques->a.tail->prev->data;
	sort_three_case(deques, a, b, c);
}

void	sort_four(t_twodeque *deques, int min)
{
	t_node	*node;
	int		top_cnt;
	int		bot_cnt;

	node = deques->a.head->next;
	top_cnt = 0;
	bot_cnt = 0;
	decision_rot(&(deques->a), &top_cnt, &bot_cnt, &min);
	if (top_cnt < bot_cnt)
	{
		while (top_cnt--)
			ra(deques);
	}
	else
	{
		while (bot_cnt--)
			rra(deques);
	}
	if (is_sorted(&(deques->a)))
		return ;
	pb(deques);
	sort_three(deques);
	pa(deques);
}

void	sort_five(t_twodeque *deques, int min)
{
	t_node	*node;
	int		top_cnt;
	int		bot_cnt;

	node = deques->a.head->next;
	top_cnt = 0;
	bot_cnt = 0;
	decision_rot(&(deques->a), &top_cnt, &bot_cnt, &min);
	if (top_cnt < bot_cnt)
	{
		while (top_cnt--)
			ra(deques);
	}
	else
	{
		while (bot_cnt--)
			rra(deques);
	}
	if (is_sorted(&(deques->a)))
		return ;
	pb(deques);
	sort_four(deques, 2);
	pa(deques);
}

void	small_number(int cnt, t_twodeque *deques)
{
	t_deque	*a;
	t_deque	*b;

	a = &(deques->a);
	b = &(deques->b);
	if (cnt == 1)
		return ;
	else if (cnt == 2)
	{
		if (a->head->next->data > a->tail->prev->data)
			sa(deques);
		return ;
	}
	else if (cnt == 3)
		sort_three(deques);
	else if (cnt == 4)
		sort_four(deques, 1);
	else
		sort_five(deques, 1);
	return ;
}
