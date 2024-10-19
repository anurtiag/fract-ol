/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 07:09:56 by anurtiag          #+#    #+#             */
/*   Updated: 2023/12/15 07:11:14 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_data	set_julia(t_data img, char *s1, char *s2)
{
	img.fr_data.type = 1;
	if (s1 && ft_strchr(s1, '.'))
		img.fr_data.r_c = ft_cal_digit(s1);
	else if (s1 && !ft_strchr(s1, '.'))
		img.fr_data.r_c = ft_atoi(s1);
	if (s2 && ft_strchr(s2, '.'))
		img.fr_data.i_c = ft_cal_digit(s2);
	else if (s2 && !ft_strchr(s2, '.'))
		img.fr_data.i_c = ft_atoi(s2);
	return (img);
}

void	set_data(int i, char **argv)
{
	t_data	img;

	hooks_explanation();
	img.fr_data.color = 1;
	img.realx_start = -2;
	img.realx_end = 2;
	img.realy_start = -1;
	img.realy_end = 1;
	img.zoom = 1;
	img.relx = 0;
	img.rely = 0;
	img.fr_data.it = 30;
	if (i == 0)
		img.fr_data.type = 0;
	else if (i == 1)
		img = set_julia(img, argv[2], argv[3]);
	else if (i == 2)
		img.fr_data.type = 2;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, IMG_WIDTH, IMG_HEIGHT, "fract-ol");
	img.img = mlx_new_image(img.mlx, IMG_WIDTH, IMG_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, \
	&img.line_length, &img.endian);
	draw_fractal(img);
	ft_hooks(img);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 1 || argc > 4)
		ft_wrong_prmtr();
	while (argv[++i])
	{
		if (argv[i])
			verify_parameter(argv[i]);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		set_data(0, argv);
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
		set_data(1, argv);
	else if (ft_strncmp(argv[1], "ship", 4) == 0)
		set_data(2, argv);
	else
		ft_wrong_prmtr();
}
