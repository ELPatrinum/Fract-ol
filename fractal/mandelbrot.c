/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 15:07:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	mandelbrot_formula(double x, double y)
{
	double	zx;
	double	zy;
	int		iteration;
	double	temp;

	zx = 0.0;
	zy = 0.0;
	iteration = 0.0;
	while (zx * zx + zy * zy <= 4 && iteration < MAX_IT)
	{
		temp = zx * zx - zy * zy + x;
		zy = 2 * zx * zy + y;
		zx = temp;
		iteration++;
	}
	return (iteration);
}

void	generate_mandelbrot(t_data *fl)
{
	t_color	color;
	int		y;
	int		x;
	double	n_x;
	double	n_y;

	y = 0;
	while (y < fl->hight)
	{
		x = 0;
		while (x < fl->width)
		{
			n_x = scale_it(x, fl, 'x') + fl->ofst_x;
			n_y = scale_it(y, fl, 'y') + fl->ofst_y;
			color = generate_color(mandelbrot_formula(n_x, n_y), fl);
			mlx_put_pixel(fl->img, x, y, (color.red << 16) | (color.green << 8)
				| color.blue);
			x++;
		}
		y++;
	}
}

void	run_mandelbrot(t_data *fl)
{
	generate_mandelbrot(fl);
	mlx_key_hook(fl->mlx, (mlx_keyfunc)ky_input, fl);
	mlx_scroll_hook(fl->mlx, (mlx_scrollfunc)scroll_input, fl);
	mlx_resize_hook(fl->mlx, (mlx_resizefunc)mlx_resize_fn, fl);
	mlx_loop(fl->mlx);
	mlx_terminate(fl->mlx);
}
