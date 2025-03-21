/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:21:08 by lzannis           #+#    #+#             */
/*   Updated: 2025/02/23 01:17:41 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_pix(t_window *w_d, int x, int y)
{
	if (w_d->new_color == 0)
		image_pixel_put(w_d, x, y, give_color(w_d));
	else if (w_d->new_color == 1)
		image_pixel_put(w_d, x, y, give_color_gray(w_d));
	else if (w_d->new_color == 2)
		image_pixel_put(w_d, x, y, gradient_red(w_d));
	else if (w_d->new_color == 3)
		image_pixel_put(w_d, x, y, gradient_red_bright(w_d));
	else if (w_d->new_color == 4)
		image_pixel_put(w_d, x, y, gradient_green(w_d));
	else if (w_d->new_color == 5)
		image_pixel_put(w_d, x, y, gradient_green_neutral(w_d));
	else if (w_d->new_color == 6)
		image_pixel_put(w_d, x, y, give_color_inverted(w_d));
	else if (w_d->new_color == 7)
		image_pixel_put(w_d, x, y, give_color_blue(w_d));
	else if (w_d->new_color == 8)
		image_pixel_put(w_d, x, y, gradient_true_red(w_d));
	else if (w_d->new_color == 9)
		image_pixel_put(w_d, x, y, give_color_true_green(w_d));
}

// Zn+1 = Zn2 + C
void	ft_mandelbrot(t_window *w_d)
{
	w_d->pt.tmp = w_d->pt.z1;
	w_d->pt.z1 = ((w_d->pt.z1 * w_d->pt.z1) - (w_d->pt.z2 * w_d->pt.z2));
	w_d->pt.z2 = 2 * w_d->pt.tmp * w_d->pt.z2;
	w_d->pt.z1 += w_d->pt.c1;
	w_d->pt.z2 += w_d->pt.c2;
}

void	ft_burning_ship(t_window *w_d)
{
	w_d->pt.tmp = w_d->pt.z1;
	w_d->pt.z1 = ((w_d->pt.z1 * w_d->pt.z1) - (w_d->pt.z2 * w_d->pt.z2));
	w_d->pt.z2 = 2 * ft_abs((w_d->pt.tmp * w_d->pt.z2));
	w_d->pt.z1 += w_d->pt.c1;
	w_d->pt.z2 += w_d->pt.c2;
}

void	ft_coordonate_mandelbrot(t_window *w_d, int x, int y)
{
	w_d->pt.c1 = (norm(x, WIDTH, -2, 2) * w_d->zoom) + w_d->shift_x;
	w_d->pt.c2 = (norm(y, HEIGHT, -2, 2) * w_d->zoom) + w_d->shift_y;
	w_d->pt.z1 = 0;
	w_d->pt.z2 = 0;
	w_d->count = 0;
	while (w_d->count <= w_d->max_iteration)
	{
		if (w_d->name.fractal == 1)
			ft_mandelbrot(w_d);
		else if (w_d->name.fractal == 3)
			ft_burning_ship(w_d);
		if (w_d->pt.z1 * w_d->pt.z1 + w_d->pt.z2 * w_d->pt.z2 > 4)
		{
			color_pix(w_d, x, y);
			return ;
		}
		w_d->count++;
	}
	image_pixel_put(w_d, x, y, TRGB_BLACK);
}

void	ft_coordonate_julia(t_window *w_d, int x, int y)
{
	w_d->count = 0;
	w_d->pt.z1 = (norm(x, WIDTH, -2, 2) * w_d->zoom) + w_d->shift_x;
	w_d->pt.z2 = (norm(y, HEIGHT, 2, -2) * w_d->zoom) + w_d->shift_y;
	while (w_d->pt.z1 * w_d->pt.z1 + w_d->pt.z2 * w_d->pt.z2 <= 4
		&& w_d->count < w_d->max_iteration)
	{
		w_d->pt.tmp = w_d->pt.z1 * w_d->pt.z1 - w_d->pt.z2 * w_d->pt.z2;
		w_d->pt.z2 = 2 * w_d->pt.z1 * w_d->pt.z2 + w_d->pt.c2_julia;
		w_d->pt.z1 = w_d->pt.tmp + w_d->pt.c1_julia;
		w_d->count++;
	}
	if (w_d->count == w_d->max_iteration)
		image_pixel_put(w_d, x, y, TRGB_BLACK);
	else
		color_pix(w_d, x, y);
}
