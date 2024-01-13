/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muel-bak <muel-bak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 20:54:14 by muel-bak          #+#    #+#             */
/*   Updated: 2024/01/13 19:24:21 by muel-bak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
#define START "\
┏┓┳┓┏┓┏┓┏┳┓┏┓┓ \n\
┣ ┣┫┣┫┃  ┃ ┃┃┃ \n\
┻ ┛┗┛┗┗┛ ┻ ┗┛┗┛\n\
              by_muel-bak:\n\
"
# define D 720.0;
# define ERROR_MSG	"To use the program fractol you shoud enter one of these\
 argument:\n\tMandelbort or Julia\n\tand btw julia takes 2 more arguments,\
  \n        wich represent the complex number\n"
# define MAX_IT 40.0


typedef struct t_color 
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} t_color;


typedef struct s_data
{
	mlx_t *mlx;
	mlx_image_t *img;
	double zm_ix;
	double	julia_x;
	double	julia_y;
	double	ofst_x;
	double	ofst_y;
	char	name;
	int		color_ix;
	double width;
	double hight;
} t_data;

t_color generate_color(int iteration, t_data *fl);
//=============_helping_finctions_==============
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	ft_putstr_fd(char *s, int fd);
double	ft_atoi(const char *str);
//=================_eroor_======================
bool	is_valid(char *s1, char *s2);
//=============_fractal_tools_==================
void	init_fractal(mlx_t* mlx, mlx_image_t **image, t_data *fl);
void	ky_input(mlx_key_data_t keydata, t_data *fl);
void	scroll_input(double xdelta, double ydelta, t_data *fl);
double scale_it(int coord, t_data *fl, char c);
void	mlx_resize_fn(int32_t width, int32_t height, t_data *fl);
//=============_Mandelbrot_==================
void run_mandelbrot(t_data *fl);
void	generate_mandelbrot(t_data *fl);
void	re_gen(t_data *fl);;
//=============_Julia_==================
void run_julia(t_data *fl);
void	generate_julia(t_data *fl);



void generate_burning_ship(t_data *fl)

#endif
