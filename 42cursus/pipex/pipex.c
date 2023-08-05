/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:04:48 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/05 17:02:04 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./libft/ft_printf.h"

int	main(int ac, char **av)
{
	if (ac != 5)
	{
		ft_putstr_fd(strerror(EINVAL), 2);
		return (0);
	}
	execve(av[2], NULL, NULL);
}
