/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sand_clock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:39:55 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/17 16:45:10 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	decision_rot(t_deque *deque, int *top_cnt, int *bot_cnt, int *cnt)
{
	t_node	*node;

	node = deque->head->next;
	while (node != deque->tail)
	{
		if (node->data == (*cnt) - 1)
			break ;
		(*top_cnt)++;
		node = node->next;
	}
	node = deque->tail->prev;
	while (node != deque->head)
	{
		if (node->data == (*cnt) - 1)
			break ;
		(*bot_cnt)++;
		node = node->prev;
	}
	(*cnt)--;
	(*bot_cnt)++;
}

void	b_to_a(t_twodeque *deques, int cnt)
{
	int	top_cnt;
	int	bot_cnt;

	while (deques->b.size)
	{
		top_cnt = 0;
		bot_cnt = 0;
		decision_rot(&(deques->b), &top_cnt, &bot_cnt, &cnt);
		if (top_cnt < bot_cnt)
		{
			while (top_cnt--)
				rb(deques);
		}
		else
		{
			while (bot_cnt--)
				rrb(deques);
		}
		pa(deques);
	}
}

void	a_to_b(t_twodeque *deques, int chunck)
{
	int	num;

	num = 0;
	while (deques->a.size)
	{
		if (get_front(&(deques->a)) <= num)
		{
			pb(deques);
			num++;
		}
		else if (get_front(&(deques->a)) > num
			&& get_front(&(deques->a)) <= num + chunck)
		{
			pb(deques);
			rb(deques);
			num++;
		}
		else if (get_front(&(deques->a)) > num + chunck)
			ra(deques);
	}
}

void	sand_clock_algo(int cnt, t_twodeque *deques)
{
	int		chunck;

	chunck = (0.000000053 * cnt * cnt) + (0.03 * cnt) + 14.5;
	a_to_b(deques, chunck);
	b_to_a(deques, cnt);
}
