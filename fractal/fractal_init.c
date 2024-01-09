/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:08:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/09 20:14:42 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_input(mlx_key_data_t keydata, t_data *fl)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(fl->mlx);
		exit(0);
	}
	if (keydata.key == MLX_KEY_KP_ADD)
	{
		mlx_delete_image(fl->mlx, fl->img);
		*(fl->zm_ix) *= 0.99;
		if (!(fl->img = mlx_new_image(fl->mlx, WIDTH, HEIGHT)))
		{
			mlx_close_window(fl->mlx);
			puts(mlx_strerror(mlx_errno));
			exit (EXIT_FAILURE);
		}
		mlx_image_to_window(fl->mlx, fl->img, 0, 0);
		generate_mandelbrot(fl);
	}
	if (keydata.key == MLX_KEY_KP_SUBTRACT)
	{
		mlx_delete_image(fl->mlx, fl->img);
		*(fl->zm_ix) *= 1.01;
		if (!(fl->img = mlx_new_image(fl->mlx, WIDTH, HEIGHT)))
		{
			mlx_close_window(fl->mlx);
			puts(mlx_strerror(mlx_errno));
			exit (EXIT_FAILURE);
		}
		mlx_image_to_window(fl->mlx, fl->img, 0, 0);
		generate_mandelbrot(fl);
	}
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
