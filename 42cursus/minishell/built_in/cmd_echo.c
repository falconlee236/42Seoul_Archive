/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 01:40:57 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/05 15:27:04 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static int	check_option(char *str)
{
	size_t	i;

	if (str[0] != '-')
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static void	setup_echo(char **argv, int *is_n, size_t *i)
{
	*i = 0;
	*is_n = 0;
	if (!argv[1])
		return ;
	*i = 1;
	while (argv[*i])
	{
		if (check_option(argv[*i]))
			*is_n = 1;
		else
			break ;
		(*i)++;
	}
}

int	cmd_echo(char **argv)
{
	int		is_n;
	size_t	i;

	setup_echo(argv, &is_n, &i);
	if (i == 0)
		printf("\n");
	else
	{
		if (!argv[i])
			return (1);
		while (argv[i])
		{
			printf("%s", argv[i]);
			i++;
			if (argv[i])
				printf(" ");
		}
		if (!is_n)
			printf("\n");
	}
	return (0);
}
