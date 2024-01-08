/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:08:41 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/07 15:30:23 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	close_wnd(mlx_key_data_t keydata, mlx_t* mlx)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(mlx);
		exit(0);
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
