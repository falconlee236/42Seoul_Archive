/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 15:15:07 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/19 16:09:31 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft/get_next_line.h"
#include "libft/ft_printf.h"

int	run_command(t_twodeque *deques, char *command)
{
	if (ft_strlen(command) == 3 && ft_strncmp(command, "sa\n", 3) == 0)
		sa(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "sb\n", 3) == 0)
		sb(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "ss\n", 3) == 0)
		ss(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "pa\n", 3) == 0)
		pa(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "pb\n", 3) == 0)
		pb(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "ra\n", 3) == 0)
		ra(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "rb\n", 3) == 0)
		rb(deques);
	else if (ft_strlen(command) == 3 && ft_strncmp(command, "rr\n", 3) == 0)
		rr(deques);
	else if (ft_strlen(command) == 4 && ft_strncmp(command, "rra\n", 4) == 0)
		rra(deques);
	else if (ft_strlen(command) == 4 && ft_strncmp(command, "rrb\n", 4) == 0)
		rrb(deques);
	else if (ft_strlen(command) == 4 && ft_strncmp(command, "rrr\n", 4) == 0)
		rrr(deques);
	else
		return (0);
	return (1);
}

int	check(t_twodeque *deques)
{
	char	*command;
	t_node	*cur;

	command = get_next_line(0);
	while (command)
	{
		if (!run_command(deques, command))
			return (0);
		command = get_next_line(0);
	}
	cur = deques->a.head->next;
	while (cur->next != deques->a.tail)
	{
		if (cur->data > cur->next->data)
			return (0);
		cur = cur->next;
	}
	if (!is_empty(&(deques->b)))
		return (0);
	return (1);
}

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
	twodeque_init(&deques);
	i = 0;
	while (i < argc - 1)
		push_back(&deques.a, arr[i++]);
	if (deques.a.size > 1 && !check(&deques))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (1);
}
