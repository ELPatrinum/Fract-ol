/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:11:58 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 15:48:08 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	d_v(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i])
	{
		count++;
		i++;
	}
	return (count);
}

static double	calc_result(double tmp, double result, char c, int sign)
{
	tmp = (result * 10) + (c - 48);
	if (tmp < result && sign == 1)
		return (-1);
	else if (tmp < result && sign == -1)
		return (0);
	return (tmp);
}

static void	ft_helper(const char *str, double *result, int *sign, double *tmp)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
	{
		if (str[i] == '.')
			i++;
		else
		{
			*result = calc_result(*tmp, *result, str[i], *sign);
			i++;
		}
	}
}

double	ft_atoi(const char *str)
{
	int		sign;
	double	result;
	double	tmp;

	if (!str)
		return (0);
	sign = 1;
	result = 0;
	tmp = 0;
	ft_helper(str, &result, &sign, &tmp);
	if (d_v(str))
		result = (result / (pow(10, d_v(str))));
	return (result * sign);
}
