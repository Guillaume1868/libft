/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaubert <gaubert@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:10:34 by gaubert           #+#    #+#             */
/*   Updated: 2021/10/13 11:37:36 by gaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wc(const char *str, char c)
{
	int			cnt;
	int			once;

	cnt = 0;
	once = 0;
	while (*str)
	{
		if (*str != c && once == 0)
		{
			once = 1;
			cnt++;
		}
		else if (*str == c)
			once = 0;
		str++;
	}
	return (cnt);
}

static char	*word_dup(const char *str, int start, int end)
{
	char		*res;
	int			i;

	i = 0;
	res = malloc(sizeof(char) * (end - start + 1));
	while (start < end)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	char		**res;
	int			idx;

	res = malloc(sizeof(char *) * (wc(s, c) + 1));
	if (!s || !res)
		return (0);
	i = 0;
	j = 0;
	idx = -1;
	while (i <= (int) ft_strlen(s))
	{
		if (s[i] != c && idx < 0)
			idx = i;
		else if ((s[i] == c || i == (int) ft_strlen(s)) && idx >= 0)
		{
			res[j++] = word_dup(s, idx, i);
			idx = -1;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
