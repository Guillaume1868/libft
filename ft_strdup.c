/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaubert <gaubert@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:44:14 by gaubert           #+#    #+#             */
/*   Updated: 2021/10/12 08:11:47 by gaubert          ###   ########.fr       */
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
