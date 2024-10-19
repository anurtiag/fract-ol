/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anurtiag <anurtiag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:30:04 by anurtiag          #+#    #+#             */
/*   Updated: 2023/12/15 07:11:51 by anurtiag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	verify_parameter(char *s)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '.' && i != 0)
		{
			control = 1;
			i++;
		}
		if (!((s[i] == '-' && i == 0) || (s[i] >= '0' && \
		s[i] <= '9') || (s[i] == '.' && control != 1)))
			ft_wrong_prmtr();
		i++;
	}
}

int	ft_end(void)
{
	exit(0);
}

double	ft_cal_digit(char *s)
{
	double	num;
	double	d_num;
	char	*c_num;
	char	*c_d_num;

	c_num = ft_substr(s, 0, ft_strchr(s, '.') - s + 1);
	if (c_num == NULL)
		ft_end();
	c_d_num = ft_strdup(ft_strchr(s, '.') + 1);
	if (c_d_num == NULL)
	{
		free(c_num);
		ft_end();
	}
	num = ft_atoi(c_num);
	d_num = ft_atoi(c_d_num);
	if (num >= 0)
		num += (d_num / 10 * ft_strlen(c_d_num));
	else
		num -= (d_num / 10 * ft_strlen(c_d_num));
	free(c_num);
	free(c_d_num);
	return (num);
}

void	ft_wrong_prmtr(void)
{
	ft_printf ("%s%s%s%s",
		"Wrong parameters, please try again with:\n",
		"mandelbrot, julia or ship as first parameter.\n",
		"You can also provide the coordinates you want by passing the number",
		" as a parameter and using a period for the decimal.\n");
	ft_end();
}

void	hooks_explanation(void)
{
	ft_printf("%s%s%s%s%s%s",
		"Use the mouse wheel to zoom in/out.\n",
		"Type +/- to increase/reduce de number of iterations.\n",
		"Type c to change colors.",
		"Type the arrows to move the image.\n",
		"In the Julia fractal, move the mouse over the window",
		" to see the changes in the fractal.\n");
}
