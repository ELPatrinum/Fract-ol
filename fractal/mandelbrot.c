/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:08:49 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/07 18:27:11 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	mandelbrot_formula(void *img_ptr, int x, int y)
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	int		  iteration;
	t_color color;
	double	temp;

	cx = (x - WIDTH / 2) * 4.0 / WIDTH;
	cy = (y - HEIGHT / 2) * 4.0 / WIDTH;
	zx = (x - WIDTH / 2) * 4.0 / WIDTH;
	zy = (y - HEIGHT / 2) * 4.0 / WIDTH;
	iteration = 0;
	while (zx * zx + zy * zy <= 4 && iteration < MAX_IT)
	{
		temp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = temp;
		iteration++;
	}
	color = generate_color(iteration);
	mlx_put_pixel(img_ptr, x, y, (color.red << 16) | (color.green << 8) | color.blue);
}

static void	generate_mandelbrot(void *mlx_ptr, void *img_ptr)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mandelbrot_formula(img_ptr, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx_ptr, img_ptr, WIDTH, HEIGHT);
}

void run_mandelbrot(mlx_t *mlx, mlx_image_t **image)
{
	generate_mandelbrot(mlx, *image);
	mlx_key_hook(mlx, (mlx_keyfunc)close_wnd, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
