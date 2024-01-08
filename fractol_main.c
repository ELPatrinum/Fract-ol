/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:01:05 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/07 18:05:55 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	double		j_x;
	double		j_y;

	image = NULL;
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
	{
		if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1)))
			return (puts(mlx_strerror(mlx_errno)), 1);
		init_fractal(mlx, &image);
		run_mandelbrot(mlx, &image);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5) && is_valid(av[2], av[3]))
	{
		if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1)))
			return (puts(mlx_strerror(mlx_errno)), 1);
		j_x = ft_atoi(av[2]);
		j_y = ft_atoi(av[3]);
		init_fractal(mlx, &image);
		run_julia(mlx, &image, &j_x, &j_y);
	}
  ft_putstr_fd(ERROR_MSG, 2); 
}
