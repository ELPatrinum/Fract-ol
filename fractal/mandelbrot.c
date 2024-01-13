/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 15:13:08 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int mandelbrot_formula(t_data *fl, double x, double y)
{
    (void)fl;
    double zx = 0.0;
    double zy = 0.0;
    int iteration = 0;

    while (zx * zx + zy * zy <= 4 && iteration < MAX_IT)
    {
        double temp = zx * zx - zy * zy + x;
        zy = 2 * zx * zy + y;
        zx = temp;
        iteration++;
    }
    return iteration;
}

void generate_mandelbrot(t_data *fl)
{
	t_color color;
    int y = 0;
    while (y < HEIGHT)
    {
        int x = 0;
        while (x < WIDTH)
        {
            double n_x = scale_it(x, fl) + fl->ofst_x;
            double n_y = scale_it(y, fl) + fl->ofst_y;
            color = generate_color(mandelbrot_formula(fl, n_x, n_y), fl);
            mlx_put_pixel(fl->img, x, y, (color.red << 16) | (color.green << 8) | color.blue);
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
