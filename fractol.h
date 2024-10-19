/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:34:54 by anurtiag          #+#    #+#             */
/*   Updated: 2023/12/15 07:02:54 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include "lib/ft_printf/libftprintf.h"
# include "lib/Libft/libft.h"
# include "lib/mlx/mlx.h"

# define IMG_WIDTH 1920
# define IMG_HEIGHT 1080
# define IMGX_CENTER 960
# define IMGY_CENTER 540

typedef struct s_mouse
{
	double	mousex;
	double	mousey;
}				t_mouse;

typedef struct s_fractal
{
	double	r_c;
	double	i_c;
	double	r_z;
	double	i_z;
	int		it;
	int		type;
	int		color;
}				t_fractal;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	double		realx_start;
	double		realx_end;
	double		realy_start;
	double		realy_end;
	double		relx;
	double		rely;
	double		zoom;
	t_mouse		mouse;
	t_fractal	fr_data;
}				t_data;

void	ft_hooks(t_data img);
int		key_press_hook(int keycode, t_data *img);
int		mouse_hook(int button, int x, int y, t_data *img);
int		mouse_hook(int button, int x, int y, t_data *img);
int		ft_motion_hook(int x, int y, t_data *img);
int		ft_end(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_put_color(int i, int x, int y, t_data img);
t_data	cal_zoom(t_data img, int x, int y);
int		ft_is_julia(t_data	img);
int		ft_is_burning_ship(t_data	img);
int		ft_is_mandelbrot(t_data img);
void	draw_fractal(t_data	img);
t_data	move_fractal_y(t_data new_img, int i);
t_data	move_fractal_x(t_data new_img, int i);
t_data	change_it(t_data new_img, int i);
t_data	change_color(t_data new_img, int i);
double	ft_cal_digit(char *s);
t_data	set_julia(t_data img, char *s1, char *s2);
void	ft_wrong_prmtr(void);
void	verify_parameter(char *s);
void	set_data(int i, char **argv);
void	hooks_explanation(void);

#endif