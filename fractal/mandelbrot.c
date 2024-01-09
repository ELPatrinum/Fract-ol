/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/09 22:32:03 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	mandelbrot_formula(t_data *fl, int x, int y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	int		  iteration;
	t_color color;
	double	temp;
	
	cx = (x - WIDTH / 2) * (*(fl->zm_ix))/ WIDTH;
	cy = (y - HEIGHT / 2) * (*(fl->zm_ix))/ WIDTH;
	zx = (x - WIDTH / 2) * (*(fl->zm_ix))/ WIDTH;
	zy = (y - HEIGHT / 2) * (*(fl->zm_ix))/ WIDTH;
	iteration = 0;
	while (zx * zx + zy * zy <= 4 && iteration < MAX_IT)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iteration++;
	}
	color = generate_color(iteration);
	mlx_put_pixel(fl->img, x, y, (color.red << 16) | (color.green << 8) | color.blue);
}

void	generate_mandelbrot(t_data *fl)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_formula(fl, x, y);
			x++;
		}
		y++;
	}
}

void run_mandelbrot(t_data *fl)
{
	generate_mandelbrot(fl);
	mlx_key_hook(fl->mlx, (mlx_keyfunc)ky_input, fl);
	mlx_scroll_hook(fl->mlx, (mlx_scrollfunc)scroll_input, fl);
	mlx_loop(fl->mlx);
	mlx_terminate(fl->mlx);
}
