/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:22:40 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/15 16:07:16 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	start_mandelbrot(t_data fl)
{
	fl.name = 'm';
	fl.mlx = mlx_init(fl.width, fl.hight, "MLX42", 1);
	if (!(fl.mlx))
		return (false);
	init_fractal(fl.mlx, &fl.img, &fl);
	run_mandelbrot(&fl);
	return (true);
}

static bool	start_julia(t_data fl, char **av)
{
	fl.name = 'j';
	fl.mlx = mlx_init(fl.width, fl.hight, "MLX42", 1);
	if (!(fl.mlx))
		return (false);
	fl.julia_x = ft_atoi(av[2]);
	fl.julia_y = ft_atoi(av[3]);
	init_fractal(fl.mlx, &fl.img, &fl);
	run_julia(&fl);
	return (true);
}

static bool	start_burning(t_data fl)
{
	fl.name = 'b';
	fl.mlx = mlx_init(fl.width, fl.hight, "MLX42", 1);
	if (!(fl.mlx))
		return (false);
	init_fractal(fl.mlx, &fl.img, &fl);
	run_burning_ship(&fl);
	return (true);
}

int	main(int ac, char **av)
{
	t_data	fl;

	(1 == 1) && (fl.img = NULL, fl.zm_ix = 1.0);
	(1 == 1) && (fl.ofst_x = 0.0, fl.ofst_y = 0.0, fl.color_ix = 1);
	(1 == 1) && (fl.width = 720.0, fl.hight = 720.0, fl.max_it = 40);
	ft_putstr_fd(START, 1);
	if (ac == 2 && !ft_strncmp(av[1], "Mandelbrot", 10))
	{
		if (!start_mandelbrot(fl))
			return (puts(mlx_strerror(mlx_errno)), 1);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "Julia", 5)
		&& is_valid(av[2], av[3]))
	{
		if (!(start_julia(fl, av)))
			return (puts(mlx_strerror(mlx_errno)), 1);
	}
	else if (ac == 2 && !ft_strncmp(av[1], "Burningship", 11))
	{
		if (!(start_burning(fl)))
			return (puts(mlx_strerror(mlx_errno)), 1);
	}
	else
		ft_putstr_fd(BSERROR, 2); 
}
