/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:20:28 by lzannis           #+#    #+#             */
/*   Updated: 2025/02/19 15:20:50 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_innit(t_window *w_d)
{
	w_d->max_iteration = 20;
	w_d->shift_x = 0.0;
	w_d->shift_y = 0.0;
	w_d->zoom = 1.0;
	w_d->name.fractal = 0;
	w_d->new_color = 0;
}

void	create_window(t_window *win_dis)
{
	win_dis->mlx_ptr = mlx_init();
	if (!win_dis->mlx_ptr)
	{
		free(win_dis->mlx_ptr);
		return ;
	}
	win_dis->win_ptr = mlx_new_window(win_dis->mlx_ptr, WIDTH, HEIGHT, "win3");
	if (!win_dis->win_ptr)
		return ;
	win_dis->image_ptr = mlx_new_image(win_dis->mlx_ptr, WIDTH, HEIGHT);
	if (!win_dis->image_ptr)
		return ;
	win_dis->address = mlx_get_data_addr(win_dis->image_ptr, \
		&win_dis->bits_per_pixel, &win_dis->size_line, &win_dis->endian);
	if (!win_dis->address)
		return ;
}

void	draw_image(t_window *w_d)
{
	fill_frame(w_d);
	mlx_put_image_to_window (w_d->mlx_ptr, w_d->win_ptr, \
		w_d->image_ptr, 0, 0);
	mlx_hook(w_d->win_ptr, 2, 1L << 0, key_hook, w_d);
	mlx_mouse_hook(w_d->win_ptr, mouse_hook, w_d);
	mlx_hook(w_d->win_ptr, 17, 0, close_win, w_d);
	mlx_loop(w_d->mlx_ptr);
}

void	image_pixel_put(t_window *img, int x, int y, int color)
{
	char	*dst;

	if ((x > WIDTH) || (y > HEIGHT))
		return ;
	dst = img->address + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_frame(t_window *win_dis)
{
	int				x;
	int				y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (win_dis->name.fractal != 2)
				ft_coordonate_mandelbrot(win_dis, x, y);
			if (win_dis->name.fractal == 2)
				ft_coordonate_julia(win_dis, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window (win_dis->mlx_ptr, win_dis->win_ptr, \
		win_dis->image_ptr, 0, 0);
}
