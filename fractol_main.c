/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:01:05 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/09 22:22:28 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data fl;
	double		ix;

	fl.img = NULL;
	ix = 4.0;
	fl.zm_ix = &ix;
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
	{
		fl.check = 1;
		if (!(fl.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1)))
			return (puts(mlx_strerror(mlx_errno)), 1);
		init_fractal(fl.mlx, &fl.img);
		run_mandelbrot(&fl);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5) && is_valid(av[2], av[3]))
	{
		fl.check = 2;
		if (!(fl.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", 1)))
			return (puts(mlx_strerror(mlx_errno)), 1);
		fl.julia_x = ft_atoi(av[2]);
		fl.julia_y = ft_atoi(av[3]);
		init_fractal(fl.mlx, &fl.img);
		run_julia(&fl);
	}
  ft_putstr_fd(ERROR_MSG, 2); 
}
