/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:06:07 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/12 20:13:29 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	parent_middle(t_pipes pipes)
{
	if (!(pipes.step % 2))
	{
		close(pipes.a[1]);
		close(pipes.b[0]);
	}
	else
	{
		close(pipes.b[1]);
		close(pipes.a[0]);
	}
}

static	void	parent_end(t_pipes pipes)
{
	if (!(pipes.step % 2))
	{
		close(pipes.a[1]);
		close(pipes.b[0]);
	}
	else
	{
		close(pipes.a[0]);
		close(pipes.b[1]);
	}
}

void	parent_proc(t_pipes pipes)
{
	if (pipes.step == 0)
		close(pipes.a[1]);
	else if (pipes.step == pipes.cnt - 1)
		parent_middle(pipes);
	else
		parent_end(pipes);
}
