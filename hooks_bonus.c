/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 07:48:28 by anurtiag          #+#    #+#             */
/*   Updated: 2023/12/15 07:12:21 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	ft_motion_hook(int x, int y, t_data *img)
{
	t_data	new_img;

	new_img = *(t_data *)img;
	new_img.fr_data.r_c = (x + new_img.relx - IMGX_CENTER) * \
	((new_img.realx_end - new_img.realx_start) / IMG_WIDTH);
	new_img.fr_data.i_c = (y + new_img.rely - IMGY_CENTER) * \
	((new_img.realy_end - new_img.realy_start) / IMG_HEIGHT);
	mlx_clear_window(new_img.mlx, new_img.win);
	draw_fractal(new_img);
	mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
	*(t_data *)img = new_img;
	return (0);
}

void	ft_hooks(t_data img)
{
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win, 2, 0, key_press_hook, &img);
	mlx_hook(img.win, 17, 0, ft_end, &img);
	if (img.fr_data.type == 1)
		mlx_hook(img.win, 6, 0, ft_motion_hook, &img);
	mlx_mouse_hook (img.win, mouse_hook, &img);
	mlx_loop(img.mlx);
}

int	key_press_hook(int keycode, t_data *img)
{
	t_data	new_img;

	new_img = *(t_data *)img;
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx, img->win);
		ft_end();
	}
	if (keycode == 126)
		*(t_data *)img = move_fractal_y(new_img, -10);
	if (keycode == 125)
		*(t_data *)img = move_fractal_y(new_img, 10);
	if (keycode == 124)
		*(t_data *)img = move_fractal_x(new_img, 10);
	if (keycode == 123)
		*(t_data *)img = move_fractal_x(new_img, -10);
	if (keycode == 44)
		*(t_data *)img = change_it(new_img, -10);
	if (keycode == 30)
		*(t_data *)img = change_it(new_img, 10);
	if (keycode == 8)
		*(t_data *)img = change_color(new_img, 13);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *img)
{
	t_data	new_img;

	new_img = *(t_data *)img;
	if (button == 4)
	{
		mlx_clear_window(new_img.mlx, new_img.win);
		new_img.zoom /= 1.2;
		new_img = cal_zoom(new_img, x, y);
		draw_fractal(new_img);
		mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
		*(t_data *)img = new_img;
	}
	else if (button == 5)
	{
		mlx_clear_window(new_img.mlx, new_img.win);
		new_img.zoom *= 1.2;
		new_img = cal_zoom(new_img, x, y);
		draw_fractal(new_img);
		mlx_put_image_to_window(new_img.mlx, new_img.win, new_img.img, 0, 0);
		*(t_data *)img = new_img;
	}
	return (0);
}
