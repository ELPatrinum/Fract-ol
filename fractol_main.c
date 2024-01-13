/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:01:05 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 19:15:18 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	start_mandelbrot(t_data fl)
{
	fl.name = 'm';
	if (!(fl.mlx = mlx_init(fl.width, fl.hight, "MLX42", 1)))
		return (false);
	init_fractal(fl.mlx, &fl.img, &fl);
	run_mandelbrot(&fl);
	return (true);
}

static bool	start_julia(t_data fl, char **av)
{
	fl.name = 'j';
	if (!(fl.mlx = mlx_init(fl.width, fl.hight, "MLX42", 1)))
		return (false);
	fl.julia_x = ft_atoi(av[2]);
	fl.julia_y = ft_atoi(av[3]);
	init_fractal(fl.mlx, &fl.img, &fl);
	run_julia(&fl);
	return (true);
}

int main(int ac, char **av)
{
	t_data fl;

	(1 == 1) && (fl.img = NULL, fl.zm_ix = 1.0);
	(1 == 1) && (fl.ofst_x = 0.0, fl.ofst_y = 0.0, fl.color_ix = 1);
	(1 == 1) && (fl.width = 720.0, fl.hight = 720.0);
	ft_putstr_fd(START, 1);
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
	{
		if (!start_mandelbrot(fl))
			return (puts(mlx_strerror(mlx_errno)), 1);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5) && is_valid(av[2], av[3]))
	{
		if (!(start_julia(fl, av)))
			return (puts(mlx_strerror(mlx_errno)), 1);
	}
	else
		ft_putstr_fd(ERROR_MSG, 2); 
}
