/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:02:18 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 15:55:16 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	julia_formula(t_data *fl, double x, double y)
{
	double	c[2];
	double	z[2];
	int		iteration;
	double	temp;

	c[0] = fl->julia_x;
	c[1] = fl->julia_y;
	z[0] = x;
	z[1] = y;
	iteration = 0;
	while (z[0] * z[0] + z[1] * z[1] <= 4 && iteration < fl->max_it)
	{
		temp = z[0] * z[0] - z[1] * z[1] + c[0];
		z[1] = 2 * z[0] * z[1] + c[1];
		z[0] = temp;
		iteration++;
	}
	return (iteration);
}

void	generate_julia(t_data *fl)
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
			color = generate_color(julia_formula(fl, n_x, n_y), fl);
			mlx_put_pixel(fl->img, x, y, (color.red << 16)
				| (color.green << 8) | color.blue);
			x++;
		}
		y++;
	}
}

void	run_julia(t_data *fl)
{
	generate_julia(fl);
	mlx_key_hook(fl->mlx, (mlx_keyfunc)ky_input, fl);
	mlx_scroll_hook(fl->mlx, (mlx_scrollfunc)scroll_input, fl);
	mlx_resize_hook(fl->mlx, (mlx_resizefunc)mlx_resize_fn, fl);
	mlx_loop(fl->mlx);
	mlx_terminate(fl->mlx);
}
