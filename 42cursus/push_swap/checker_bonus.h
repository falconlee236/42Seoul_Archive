/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:13:20 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 15:04:35 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_deque
{
	unsigned int	size;
	t_node			*head;
	t_node			*tail;
}t_deque;

typedef struct s_twodeque
{
	t_deque	a;
	t_deque	b;
}t_twodeque;

void	push_back(t_deque *dq, int data);
void	push_front(t_deque *dq, int data);
void	pop_front(t_deque *dq);
void	pop_back(t_deque *dq);
int		get_front(t_deque *dq);
int		get_back(t_deque *dq);
int		is_empty(t_deque *dq);
t_node	*make_newnode(int data);
int		twodeque_init(t_twodeque *deques);

int		*check_arg(int cnt, char **input);

void	sa(t_twodeque *deques);
void	sb(t_twodeque *deques);
void	ss(t_twodeque *deques);

void	pa(t_twodeque *deques);
void	pb(t_twodeque *deques);

void	ra(t_twodeque *deques);
void	rb(t_twodeque *deques);
void	rr(t_twodeque *deques);

void	rra(t_twodeque *deques);
void	rrb(t_twodeque *deques);
void	rrr(t_twodeque *deques);
#endif