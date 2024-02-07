/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangylee <sangylee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:33:19 by sangylee          #+#    #+#             */
/*   Updated: 2023/08/08 12:45:03 by sangylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char const *deli, char c)
{
	int	i;

	i = 0;
	while (deli[i])
	{
		if (deli[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	count_word(char const *s, char const *deli)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && check_char(deli, s[i]))
			i++;
		if (s[i] != '\0')
			cnt++;
		while (s[i] && !check_char(deli, s[i]))
			i++;
	}
	return (cnt);
}

static char	*make_word(char const *s, char const *deli)
{
	char	*word;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && !check_char(deli, s[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static char	**array_free(char	**arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split_mult(char const *s, char const *deli)
{
	size_t	i;
	size_t	idx;
	char	**res;

	res = (char **)malloc((count_word(s, deli) + 1) * sizeof(char *));
	if (!res || !s)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i])
	{
		while (s[i] && check_char(deli, s[i]))
			i++;
		if (s[i] != '\0')
		{
			res[idx++] = make_word(s + i, deli);
			if (!res[idx - 1])
				return (array_free(res));
		}
		while (s[i] && !check_char(deli, s[i]))
			i++;
	}
	res[idx] = NULL;
	return (res);
}
