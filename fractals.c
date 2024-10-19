/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:03:56 by anurtiag          #+#    #+#             */
/*   Updated: 2023/11/19 06:43:58 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_julia(t_data	img)
{
	int		i;
	double	a;
	double	b;
	double	ta;
	double	tb;

	i = -1;
	a = img.fr_data.r_z;
	b = img.fr_data.i_z;
	while (++i < img.fr_data.it && (a * a) + (b * b) <= 4)
	{
		ta = (a * a) - (b * b) + img.fr_data.r_c;
		tb = (2 * (a * b)) + img.fr_data.i_c;
		if (a == ta && b == tb)
			return (img.fr_data.it);
		a = ta;
		b = tb;
	}
	return (i);
}

int	ft_is_mandelbrot(t_data img)
{
	int		i;
	double	a;
	double	b;
	double	ta;
	double	tb;

	i = -1;
	a = 0;
	b = 0;
	while (++i < img.fr_data.it && (a * a) + (b * b) <= 4)
	{
		ta = (a * a) - (b * b) + img.fr_data.r_z;
		tb = (2 * (a * b)) + img.fr_data.i_z;
		if (a == ta && b == tb)
			return (img.fr_data.it);
		a = ta;
		b = tb;
	}
	return (i);
}

int	ft_is_burning_ship(t_data	img)
{
	int		i;
	double	a;
	double	b;
	double	ta;
	double	tb;

	i = -1;
	a = img.fr_data.r_z;
	b = img.fr_data.i_z;
	while (++i < img.fr_data.it && (a * a) + (b * b) <= 4)
	{
		ta = ((a * a) - (b * b)) + (img.fr_data.r_z);
		tb = ((2 * fabs(a * b))) + (img.fr_data.i_z);
		if (a == ta && b == tb)
			return (img.fr_data.it);
		a = ta;
		b = tb;
	}
	return (i);
}
