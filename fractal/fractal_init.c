/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:08:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 15:24:05 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


void	re_gen(t_data *fl)
{
	mlx_delete_image(fl->mlx, fl->img);
	if (!(fl->img = mlx_new_image(fl->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(fl->mlx);
		puts(mlx_strerror(mlx_errno));
		exit (EXIT_FAILURE);
	}
	mlx_image_to_window(fl->mlx, fl->img, 0, 0);
	if (fl->name == 'm')
		generate_mandelbrot(fl);
	else if (fl->name == 'j')
		generate_julia(fl);
}

void	scroll_input(double xdelta, double ydelta, t_data *fl)
{
	int32_t tempx;
	int32_t tempy;
	double mx_bfr;
	double my_bfr;
	(void)xdelta;
	mlx_get_mouse_pos(fl->mlx, &tempx, &tempy);
	mx_bfr = scale_it((double)tempx, fl);
	my_bfr = scale_it((double)tempy, fl);
	if (ydelta <= 0)
		fl->zm_ix *= 0.97;
	if (ydelta >= 0)
		fl->zm_ix *= 1.03;
	fl->ofst_x += mx_bfr - (scale_it((double)tempx, fl));
	fl->ofst_y += my_bfr - (scale_it((double)tempy, fl));
	if (fl->name == 'm')
		generate_mandelbrot(fl);
	else if (fl->name == 'j')
		generate_julia(fl);
	
}

void	ky_input(mlx_key_data_t keydata, t_data *fl)
{
	int32_t tempx;
	int32_t tempy;
	double mx_bfr;
	double my_bfr;

	if (keydata.key == MLX_KEY_ESCAPE)
		(mlx_close_window(fl->mlx), exit(0));
	mlx_get_mouse_pos(fl->mlx, &tempx, &tempy);
	mx_bfr = scale_it((double)tempx, fl);
	my_bfr = scale_it((double)tempy, fl);
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
	{
		if (fl->color_ix >= 3)
			fl->color_ix = 1;
		else
			fl->color_ix++;
	}
	if (keydata.key == MLX_KEY_KP_ADD)
		fl->zm_ix *= 0.97;
	if (keydata.key == MLX_KEY_KP_SUBTRACT)
		fl->zm_ix *= 1.03;
	fl->ofst_x += mx_bfr - (scale_it((double)tempx, fl));
	fl->ofst_y += my_bfr - (scale_it((double)tempy, fl));
	if (fl->name == 'm')
		generate_mandelbrot(fl);
	else if (fl->name == 'j')
		generate_julia(fl);
	return ;
}

void	init_fractal(mlx_t *mlx, mlx_image_t **image)
{
	if (!(*image = mlx_new_image(mlx, WIDTH, HEIGHT)))
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

double scale_it(int coord,t_data *fl)
{
    return ((-2) * fl->zm_ix + ((2 * fl->zm_ix) - ((-2) * fl->zm_ix)) * (coord - 0) / (WIDTH - 0));
}