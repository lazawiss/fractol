/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:01:25 by lzannis           #+#    #+#             */
/*   Updated: 2025/03/11 15:39:51 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	give_color(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(8 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.g = (int)(15 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(5 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	give_color_inverted(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.g = (int)(8 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(3 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.r = (int)(15 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.g << 16 | w_d->grd.b << 8 | w_d->grd.r;
	return (w_d->color);
}

int	give_color_gray(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(8 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.r = (int)(15 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.r = (int)(5 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.r << 8 | w_d->grd.r;
	return (w_d->color);
}

int	give_color_blue(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(0 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.g = (int)(229 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(250 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	give_color_true_green(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(0 * (1 - w_d->grd.t) * w_d->grd.t * w_d->grd.t \
				* w_d->grd.t * 255);
	w_d->grd.g = (int)(230 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(0 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}
