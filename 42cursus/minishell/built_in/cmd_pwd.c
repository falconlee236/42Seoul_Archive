/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonyoo <yonyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:28:46 by yonyoo            #+#    #+#             */
/*   Updated: 2024/02/06 03:03:33 by yonyoo           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	cmd_pwd(void)
{
	char	*cwd;

	cwd = getcwd (NULL, 0);
	if (!cwd)
		return (1);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}
