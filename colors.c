/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:26:43 by anurtiag          #+#    #+#             */
/*   Updated: 2023/11/18 09:18:42 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	ft_put_color(int i, int x, int y, t_data img)
{
	if (i == img.fr_data.it)
		my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
	else
		my_mlx_pixel_put(&img, x, y, (i * 0xA47C1F) * img.fr_data.color);
}

void	draw_fractal(t_data	img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < IMG_HEIGHT)
	{
		x = -1;
		while (++x < IMG_WIDTH)
		{
			img.fr_data.r_z = ((x + img.relx) - (IMGX_CENTER)) * \
			(((img.realx_end - img.realx_start)) / IMG_WIDTH);
			img.fr_data.i_z = ((y + img.rely) - (IMGY_CENTER)) * \
			(((img.realy_end - img.realy_start)) / IMG_HEIGHT);
			if (img.fr_data.type == 0)
				ft_put_color(ft_is_mandelbrot(img), x, y, img);
			else if (img.fr_data.type == 1)
				ft_put_color(ft_is_julia(img), x, y, img);
			else if (img.fr_data.type == 2)
				ft_put_color(ft_is_burning_ship(img), x, y, img);
		}
	}
}
