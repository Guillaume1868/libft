/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaubert <gaubert@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 20:55:08 by gaubert           #+#    #+#             */
/*   Updated: 2021/10/14 11:49:30 by gaubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*ft_remove_spaces(char *str)
{
	int	exit;

	exit = 0;
	while (exit == 0 && *str != '\0')
	{
		if (*str == '\t' || *str == '\v' || *str == '\r' || *str == '\n')
			str++;
		else if (*str == '\f' || *str == ' ')
			str++;
		else
			exit = 1;
	}
	return (str);
}

static char	*ft_detect_minus(char *str, int *minus_count)
{
	int	exit;

	exit = 0;
	while (exit == 0 && *str != '\0')
	{
		if (*str == '-')
		{
			*minus_count += 1;
			str++;
		}
		else if (*str == '+')
			str++;
		else
			exit = 1;
	}
	return (str);
}

static void	ft_grab_int(char *str, int *result)
{
	if (*str <= '9' && *str >= '0')
	{
		*result *= 10;
		*result += *str - '0';
		str++;
		ft_grab_int(str, result);
	}
}

int	ft_atoi(char *str)
{
	int		minus_count;
	char	*str_clean;
	int		result;

	result = 0;
	minus_count = 0;
	str_clean = ft_detect_minus(ft_remove_spaces(str), &minus_count);
	ft_grab_int(str_clean, &result);
	if (minus_count % 2 == 1)
		result *= -1;
	return (result);
}
