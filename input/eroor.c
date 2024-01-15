/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eroor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:08:23 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 15:50:51 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static bool	is_digit(char c)
{
	return ((c >= '0' && c <= '9') || c == '.');
}

static bool	is_all_digit(char *str, int sign)
{
	int	i;
	int	check;

	(1 == 1) && (i = 0, check = 0);
	while (str[i])
	{
		if (str[i] == '.')
			check++;
		i++;
	}
	if (check > 1)
		return (false);
	if (sign == 1)
	{
		str++;
		if (!*str)
			return (false);
	}
	while (*str)
	{
		if (!is_digit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	is_valid(char *s1, char *s2)
{
	if (s1[0] == '-' || s1[0] == '+')
		s1++;
	if (s2[0] == '-' || s2[0] == '+')
		s2++;
	return (is_all_digit(s1, 0) && is_all_digit(s2, 0));
}
