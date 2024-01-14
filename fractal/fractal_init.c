/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:08:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 17:37:34 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mlx_resize_fn(int32_t width, int32_t height, t_data *fl)
{
	fl->hight = (double)height;
	fl->width = (double)width;
	re_gen(fl);
}


void	init_fractal(mlx_t *mlx, mlx_image_t **image, t_data *fl)
{
	if (!(*image = mlx_new_image(mlx, fl->width, fl->hight)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return;
	}
	if (mlx_image_to_window(mlx, *image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return;
	}
}

double	scale_it(int coord,t_data *fl, char c)
{
	if (c == 'x')
		return ((-2) * fl->zm_ix + ((2 * fl->zm_ix) - ((-2) * fl->zm_ix))
				 * (coord - 0) / (fl->width - 0));
	else
		return ((-2) * fl->zm_ix + ((2 * fl->zm_ix) - ((-2) * fl->zm_ix))
				 * (coord - 0) / (fl->hight - 0));
}
