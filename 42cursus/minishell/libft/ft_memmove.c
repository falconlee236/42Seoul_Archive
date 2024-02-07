/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isang-yun <isang-yun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:21:06 by sangylee          #+#    #+#             */
/*   Updated: 2024/01/29 13:01:46 by isang-yun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	tmp;

	if (!src && !dst)
		return (dst);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			tmp = len - i - 1;
			*((unsigned char *)(dst + tmp)) = *((unsigned char *)(src + tmp));
			i++;
		}
	}
	return (dst);
}
