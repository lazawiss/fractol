/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 23:13:47 by lzannis           #+#    #+#             */
/*   Updated: 2025/02/22 23:22:47 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	norm(double val_init, double max_init, double min_fin, double max_fin)
{
	return ((val_init / max_init) * (max_fin - min_fin) + min_fin);
}

double	ft_abs(double nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	ft_absolute(unsigned int x, unsigned int y)
{
	int	abs1;
	int	abs2;

	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	abs1 = 1;
	abs2 = 1;
	abs1 *= x;
	abs2 *= y;
	if (abs1 > abs2)
		return (x);
	else
		return (y);
}

int	ft_min(int x, int y)
{
	int	abs1;
	int	abs2;

	if (x < 0)
			x = -x;
	if (y < 0)
			y = -y;
	abs1 = 1;
	abs2 = 1;
	abs1 *= x;
	abs2 *= y;
	if (abs1 < abs2)
		return (x);
	else
		return (y);
}

// RECALCULER LE ZOOM SOURIS(XMAX-XMIN,YMAX-YMIN)
// eps = corrige la deviance de la ligne
//  valeur_initiale / max_initiale) * (max_finale - min_finale) + min_finale)
void	normaliser_mouse(t_window *w_d, int x, int y)
{
	w_d->pos.x1 = (double)x;
	w_d->pos.x2 = (WIDTH - (double)x);
	w_d->pos.y1 = (double)y;
	w_d->pos.y2 = (HEIGHT - (double)y);
	w_d->pos.resx = w_d->pos.x1 / w_d->pos.x2;
	w_d->pos.resy = w_d->pos.y1 / w_d->pos.y2;
}
