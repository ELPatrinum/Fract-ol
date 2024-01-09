/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:07:20 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/09 22:40:52 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	zoom_in(t_data *fl)
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
	if (fl->check == 1)
		generate_mandelbrot(fl);
	if (fl->check == 2)
		generate_julia(fl);
}
void	zoom_out(t_data *fl)
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
	if (fl->check == 1)
		generate_mandelbrot(fl);
	if (fl->check == 2)
		generate_julia(fl);
}
