/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:14 by gaubert           #+#    #+#             */
/*   Updated: 2021/09/27 10:56:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*duped;
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	duped = malloc(sizeof(char) * i + 1);
	if (!duped)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		duped[i] = src[i];
		i++;
	}
	duped[i] = src[i];
	return (duped);
}