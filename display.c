/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:19:13 by lzannis           #+#    #+#             */
/*   Updated: 2025/02/19 15:20:18 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_window *w_d)
{
	mlx_destroy_image(w_d->mlx_ptr, w_d->image_ptr);
	mlx_destroy_window(w_d->mlx_ptr, w_d->win_ptr);
	mlx_destroy_display(w_d->mlx_ptr);
	free(w_d->mlx_ptr);
	exit(1);
}

void	key_hook_color(int key_sym, t_window *w_d)
{
	if (key_sym == XK_Return)
	{
		w_d->new_color = 0;
		write (1, "Here is a list of the different keys ", 38);
		write (1, "and there effects : Enter : RESET COLORS, ", 43);
		write (1, "R, G, B, T, Y, U, P, H, N : SHIFT COLORS", 41);
	}
	else if (key_sym == XK_b)
		w_d->new_color = 1;
	else if (key_sym == XK_t)
		w_d->new_color = 2;
	else if (key_sym == XK_r)
		w_d->new_color = 3;
	else if (key_sym == XK_g)
		w_d->new_color = 4;
	else if (key_sym == XK_n)
		w_d->new_color = 5;
	else if (key_sym == XK_u)
		w_d->new_color = 6;
	else if (key_sym == XK_p)
		w_d->new_color = 7;
	else if (key_sym == XK_y)
		w_d->new_color = 8;
	else if (key_sym == XK_h)
		w_d->new_color = 9;
}

void	key_up_left_right_down(int key_sym, t_window *w_d)
{
	if (key_sym == XK_Up)
	{
		if (w_d->name.fractal == 2)
		w_d->shift_y += 0.5 * w_d->zoom;
		else
		w_d->shift_y -= 0.5 * w_d->zoom;
	}
	else if (key_sym == XK_Left)
	{
		w_d->shift_x -= 0.5 * w_d->zoom;
	}
	else if (key_sym == XK_Right)
		w_d->shift_x += 0.5 * w_d->zoom;
	else if (key_sym == XK_Down)
	{
		if (w_d->name.fractal == 2)
			w_d->shift_y -= 0.5 * w_d->zoom;
		else
			w_d->shift_y += 0.5 * w_d->zoom;
	}
}

int	key_hook(int key_sym, t_window *w_d)
{
	if (key_sym == XK_Escape)
		close_win(w_d);
	key_up_left_right_down(key_sym, w_d);
	if (key_sym == XK_KP_Add)
		w_d->max_iteration *= 1.15;
	else if (key_sym == XK_KP_Subtract)
		w_d->max_iteration *= 0.85;
	key_hook_color(key_sym, w_d);
	fill_frame(w_d);
	mlx_put_image_to_window(w_d->mlx_ptr, w_d->win_ptr, \
		w_d->image_ptr, 0, 0);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_window *w_d)
{
	w_d->pos.px = (norm(x, WIDTH, -2, 2));
	w_d->pos.py = (norm(y, HEIGHT, 2, -2));
	w_d->pos.px = (w_d->pos.resx * w_d->zoom) + w_d->shift_x;
	w_d->pos.py = (w_d->pos.resy * w_d->zoom) + w_d->shift_y;
	if (button == 4)
		w_d->zoom *= 0.85;
	if (button == 5)
		w_d->zoom *= 1.15;
	if (button == 1)
		w_d->zoom *= 0.5;
	if (button == 3)
		w_d->zoom *= 2.5;
	fill_frame(w_d);
	mlx_put_image_to_window(w_d->mlx_ptr, w_d->win_ptr, \
		w_d->image_ptr, 0, 0);
	return (0);
}
