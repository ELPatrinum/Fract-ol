/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:07:20 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 16:08:22 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	re_gen(t_data *fl)
{
	mlx_delete_image(fl->mlx, fl->img);
	fl->img = mlx_new_image(fl->mlx, fl->width, fl->hight);
	if (!(fl->img))
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
	else if (fl->name == 'b')
		generate_burning_ship(fl);
}

void	ky_input_2(mlx_key_data_t keydata, t_data *fl)
{
	if (keydata.key == MLX_KEY_UP && keydata.action == 1)
		fl->ofst_y += 0.02;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == 1)
		fl->ofst_y -= 0.02;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == 1)
		fl->ofst_x -= 0.02;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == 1)
		fl->ofst_x += 0.02;
	re_gen(fl);
}

void	zoom_hand(mlx_key_data_t keydata, t_data *fl)
{
	int32_t	tempx;
	int32_t	tempy;
	double	mx_bfr;
	double	my_bfr;

	mlx_get_mouse_pos(fl->mlx, &tempx, &tempy);
	mx_bfr = scale_it((double)tempx, fl, 'x');
	my_bfr = scale_it((double)tempy, fl, 'y');
	if (keydata.key == MLX_KEY_KP_ADD && keydata.action == 1)
	{
		fl->zm_ix *= 0.97;
		fl->max_it += 2;
	}
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == 1)
	{
		fl->zm_ix *= 1.03;
		fl->max_it -= 2;
	}
	fl->ofst_x += mx_bfr - (scale_it((double)tempx, fl, 'x'));
	fl->ofst_y += my_bfr - (scale_it((double)tempy, fl, 'y'));
}

void	scroll_input(double xdelta, double ydelta, t_data *fl)
{
	int32_t	tempx;
	int32_t	tempy;
	double	mx_bfr;
	double	my_bfr;

	(void)xdelta;
	mlx_get_mouse_pos(fl->mlx, &tempx, &tempy);
	mx_bfr = scale_it((double)tempx, fl, 'x');
	my_bfr = scale_it((double)tempy, fl, 'y');
	if (ydelta <= 0)
	{
		fl->zm_ix *= 0.97;
		fl->max_it += 2;
	}
	if (ydelta >= 0)
	{
		fl->zm_ix *= 1.03;
		fl->max_it -= 2;
	}
	fl->ofst_x += mx_bfr - (scale_it((double)tempx, fl, 'x'));
	fl->ofst_y += my_bfr - (scale_it((double)tempy, fl, 'y'));
	re_gen(fl);
}

void	ky_input(mlx_key_data_t keydata, t_data *fl)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == 1)
	{
		mlx_close_window(fl->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_TAB && keydata.action == 1)
	{
		if (fl->color_ix >= 3)
			fl->color_ix = 1;
		else
			fl->color_ix++;
	}
	ky_input_2(keydata, fl);
	zoom_hand(keydata, fl);
	re_gen(fl);
}
