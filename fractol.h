/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:03:04 by lzannis           #+#    #+#             */
/*   Updated: 2025/03/19 13:03:09 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 1000
# define WIDTH 1000

// define color
# define TRGB_BLACK  0x00000000
# define TRGB_TRANSPARENT  0xFF000000
# define TRGB_RED  0x00FF0000
# define TRGB_GREEN  0x0000FF00
# define TRGB_BLUE  0x000000FF
# define TRGB_WHITE  0xFFFFFFFF

# include "minilibx-linux/mlx.h"
# include <unistd.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_fractal
{
	int	fractal;
}	t_fractal;

typedef struct s_coordonate
{
	double	c1;
	double	c2;
	double	c1_julia;
	double	c2_julia;
	double	z1;
	double	z2;
	double	tmp;
}	t_coordonate;

typedef struct s_color
{
	double	t;
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_mouse
{
	double			resx;
	double			resy;
	double			px;
	double			py;
	unsigned int	x1;
	unsigned int	y1;
	unsigned int	x2;
	unsigned int	y2;
}	t_mouse;

typedef struct s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image_ptr;
	char			*address;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				max_iteration;
	int				count;
	int				color;
	int				new_color;
	double			shift_x;
	double			shift_y;
	double			zoom;
	t_coordonate	pt;
	t_color			grd;
	t_fractal		name;
	t_mouse			pos;
}	t_window;

typedef struct s_atof
{
	double	nbr;
	int		nb;
	int		sign;
	int		len;
	int		i;
}	t_atof;

// COLORS

int		give_color(t_window *w_d);
int		give_color_inverted(t_window *w_d);
int		give_color_gray(t_window *w_d);
int		give_color_blue(t_window *w_d);
int		give_color_true_green(t_window *w_d);

// PALETTE

int		gradient_true_red(t_window *w_d);
int		gradient_red(t_window *w_d);
int		gradient_red_bright(t_window *w_d);
int		gradient_green(t_window *w_d);
int		gradient_green_neutral(t_window *w_d);

// DISPLAY

void	key_hook_color(int key_sym, t_window *w_d);
void	key_up_left_right_down(int key_sym, t_window *w_d);
int		close_win(t_window *w_d);
int		key_hook(int key_sym, t_window *w_d);
int		mouse_hook(int button, int x, int y, t_window *w_d);

// FRACTALES

void	color_pix(t_window *w_d, int x, int y);
void	ft_mandelbrot(t_window *w_d);
void	ft_burning_ship(t_window *w_d);
void	ft_coordonate_mandelbrot(t_window *w_d, int x, int y);
void	ft_coordonate_julia(t_window *w_d, int x, int y);

// IMAGE

void	ft_innit(t_window *w_d);
void	create_window(t_window *w_d);
void	draw_image(t_window *w_d);
void	image_pixel_put(t_window *img, int x, int y, int color);
void	fill_frame(t_window *w_d);

// MATH

void	normaliser_mouse(t_window *w_d, int x, int y);
int		ft_absolute(unsigned int x, unsigned int y);
double	norm(double val_init, double max_init, double min_fin, double max_fin);
double	ft_abs(double nb);

// UTILS

void	ft_putchar(char c);
void	ft_display_name(char *str, t_window *w_d);
void	ft_display_julia(t_window *w_d);
void	ft_error(char *str, t_window *w_d);
int		ft_strcmp(char *a, char *b);

// ATOF

int		ft_strlen(char *str);
int		ft_strlen_post_point(char *str);
int		ft_atoi(char *str);
double	ft_atof(char *str);
double	ft_power(t_atof *atof);

#endif
