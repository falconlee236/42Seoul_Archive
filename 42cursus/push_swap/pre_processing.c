/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:33:19 by sangylee          #+#    #+#             */
/*   Updated: 2023/07/17 16:45:32 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	ft_bubblesort(int *arr, int *tmp_arr, int cnt)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (i < cnt)
	{
		while (j < cnt)
		{
			if (tmp_arr[i] > tmp_arr[j])
				ft_swap(&tmp_arr[i], &tmp_arr[j]);
			j++;
		}
		i++;
		j = i;
	}
	i = 0;
	while (i < cnt)
	{
		if (tmp_arr[i] != arr[i])
			return (0);
		i++;
	}
	return (1);
}

static int	ft_binary_search(int start, int end, int target, int *arr)
{
	int	mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (target < arr[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return (start - 1);
}

int	indexing(int *arr, int cnt)
{
	int	i;
	int	*tmp_arr;

	i = 0;
	tmp_arr = (int *)malloc(sizeof(int) * cnt);
	while (i < cnt)
	{
		tmp_arr[i] = arr[i];
		i++;
	}
	if (ft_bubblesort(arr, tmp_arr, cnt))
		return (1);
	i = 0;
	while (i < cnt)
	{
		arr[i] = ft_binary_search(0, cnt - 1, arr[i], tmp_arr);
		i++;
	}
	free(tmp_arr);
	return (0);
}

int	is_sorted(t_deque *deque)
{
	t_node	*node;

	node = deque->head->next;
	while (node->next != deque->tail)
	{
		if (node->data > node->next->data)
			return (0);
		node = node->next;
	}
	return (1);
}
