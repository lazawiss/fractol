/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 22:40:11 by lzannis           #+#    #+#             */
/*   Updated: 2025/03/07 22:46:18 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_strcmp(char *a, char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}

void	ft_display_name(char *str, t_window *w_d)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		w_d->name.fractal = 1;
	else if (ft_strcmp(str, "julia") == 0)
	{
		write (2, "Error: the following arguments should be ", 42);
		write (2, "comprise between -1.0 and 1.0\n", 31);
		close_win(w_d);
	}
	else if (ft_strcmp(str, "burning_ship") == 0)
		w_d->name.fractal = 3;
	else if (ft_strcmp(str, "mandelbrot") != 0)
	{
		write (2, "Error: choose one of the following arguments: ", 47);
		write (2, "mandelbrot, julia or burning_ship\n", 35);
		close_win(w_d);
	}
}

void	ft_display_julia(t_window *w_d)
{
	if ((w_d->pt.c1_julia >= -2.0 && w_d->pt.c1_julia <= 1.0) \
	&& (w_d->pt.c2_julia >= -2.0 && w_d->pt.c2_julia <= 1.0))
		w_d->name.fractal = 2;
	else
	{
		write (2, "Error: the following arguments should be ", 42);
		write (2, "comprise between -1.0 and 1.0\n", 31);
		close_win(w_d);
	}
}

void	ft_error(char *str, t_window *w_d)
{
	if ((ft_strcmp(str, "mandelbrot") == 0) \
		|| (ft_strcmp(str, "burning_ship") == 0))
	{
		write (2, "Error: choose one of the following arguments: ", 47);
		write (2, "mandelbrot, julia or burning_ship\n", 35);
		close_win(w_d);
	}
}
