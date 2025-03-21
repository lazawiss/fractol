/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:46:22 by lzannis           #+#    #+#             */
/*   Updated: 2025/03/11 15:35:46 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	gradient_true_red(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(250 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.g = (int)(0 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(0 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	gradient_red(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(41 * (1 - w_d->grd.t) * w_d->grd.t * w_d->grd.t \
				* w_d->grd.t * 255);
	w_d->grd.g = (int)(3 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(5 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	gradient_red_bright(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(230 * (1 - w_d->grd.t) * w_d->grd.t * w_d->grd.t \
				* w_d->grd.t * 255);
	w_d->grd.g = (int)(11 * (1 - w_d->grd.t) * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * 255);
	w_d->grd.b = (int)(22 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	gradient_green(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(11 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.g = (int)(230 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(15 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}

int	gradient_green_neutral(t_window *w_d)
{
	w_d->grd.t = ((double)w_d->count / (double)w_d->max_iteration);
	w_d->grd.r = (int)(64 * (1 - w_d->grd.t) * w_d->grd.t \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.g = (int)(156 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* w_d->grd.t * w_d->grd.t * 255);
	w_d->grd.b = (int)(65 * (1 - w_d->grd.t) * (1 - w_d->grd.t) \
				* (1 - w_d->grd.t) * w_d->grd.t * 255);
	w_d->color = 0xFF << 24 | w_d->grd.r << 16 | w_d->grd.g << 8 | w_d->grd.b;
	return (w_d->color);
}
