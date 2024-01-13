/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:02:18 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 18:27:03 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	julia_formula(t_data *fl, double x, double y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	int		iteration;
	double	temp;

	(void)x;
	(void)y;
	cx = fl->julia_x;
	cy = fl->julia_y;
	zx = x;
	zy = y;
	iteration = 0;
	while (zx * zx + zy * zy <= 4 && iteration < MAX_IT)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iteration++;
	}
	return (iteration);
}

void	generate_julia(t_data *fl)
{
	t_color	color;
	int	y;
	int	x;

	y = 0;
	while (y < fl->hight)
	{
		x = 0;
		while (x < fl->width)
		{
            double n_x = scale_it(x, fl, 'x') + fl->ofst_x;
            double n_y = scale_it(y, fl, 'y') + fl->ofst_y;
			color = generate_color(julia_formula(fl, n_x, n_y), fl);
			mlx_put_pixel(fl->img, x, y, (color.red << 16) | (color.green << 8) | color.blue);  
			x++;
		}
		y++;
	}
}

void run_julia(t_data *fl)
{
	generate_julia(fl);
	mlx_key_hook(fl->mlx, (mlx_keyfunc)ky_input, fl);
	mlx_scroll_hook(fl->mlx, (mlx_scrollfunc)scroll_input, fl);
	mlx_loop(fl->mlx);
	mlx_terminate(fl->mlx);
}
