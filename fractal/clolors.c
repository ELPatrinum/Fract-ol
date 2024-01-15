/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clolors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:07:20 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 15:54:50 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_color	generate_color(int iteration, t_data *fl)
{
	t_color	color;
	double	t;

	t = (double)iteration / fl->max_it;
	if (fl->color_ix == 1)
	{
		color.red = (unsigned char)(9 * (1 - t) * t * t * t * 255);
		color.green = (unsigned char)(15 * (1 - t) * (1 - t) * t * t * 255);
		color.blue = (unsigned char)(8.5 * (1 - t)
				* (1 - t) * (1 - t) * t * 255);
	}
	if (fl->color_ix == 2)
	{
		color.red = (unsigned char)(12 * (1 - t) * t * 255);
		color.green = (unsigned char)(7 * (1 - t) * (1 - t) * t * 255);
		color.blue = (unsigned char)(5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	if (fl->color_ix == 3)
	{
		color.red = (unsigned char)(45 * (1 - t) * t * 255);
		color.green = (unsigned char)(40 * (1 - t) * (1 - t) * t * 255);
		color.blue = (unsigned char)(20 * (1 - t)
				* (1 - t) * (1 - t) * t * 255);
	}
	return (color);
}
