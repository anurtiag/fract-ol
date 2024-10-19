/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:24:22 by anurtiag          #+#    #+#             */
/*   Updated: 2023/11/19 12:44:13 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	cal_zoom(t_data img, int x, int y)
{
	double	intervalx;
	double	intervaly;

	img.mouse.mousex = ((x + img.relx) - IMGX_CENTER) * \
	((img.realx_end - img.realx_start) / IMG_WIDTH);
	img.mouse.mousey = ((y + img.rely) - IMGY_CENTER) * \
	((img.realy_end - img.realy_start) / IMG_HEIGHT);
	intervalx = ((img.realx_end - img.realx_start) * img.zoom);
	intervaly = ((img.realy_end - img.realy_start) * img.zoom);
	img.realx_start = img.mouse.mousex - ((intervalx / IMG_WIDTH) * x);
	img.realy_start = img.mouse.mousey - ((intervaly / IMG_HEIGHT) * y);
	img.realx_end = img.realx_start + intervalx;
	img.realy_end = img.realy_start + intervaly;
	img.relx = (img.mouse.mousex * (IMG_WIDTH / intervalx)) - (x - IMGX_CENTER);
	img.rely = (img.mouse.mousey * (IMG_HEIGHT / \
	intervaly)) - (y - IMGY_CENTER);
	img.zoom = 1;
	return (img);
}

t_data	move_fractal_y(t_data new_img, int i)
{
	new_img.rely += i;
	mlx_clear_window(new_img.mlx, new_img.win);
	draw_fractal(new_img);
	mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
	return (new_img);
}

t_data	move_fractal_x(t_data new_img, int i)
{
	new_img.relx += i;
	mlx_clear_window(new_img.mlx, new_img.win);
	draw_fractal(new_img);
	mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
	return (new_img);
}

t_data	change_it(t_data new_img, int i)
{
	if (new_img.fr_data.it > 0 && new_img.fr_data.it < 200)
		new_img.fr_data.it += i;
	mlx_clear_window(new_img.mlx, new_img.win);
	draw_fractal(new_img);
	mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
	return (new_img);
}

t_data	change_color(t_data new_img, int i)
{
	new_img.fr_data.color += i;
	mlx_clear_window(new_img.mlx, new_img.win);
	draw_fractal(new_img);
	mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
	return (new_img);
}
