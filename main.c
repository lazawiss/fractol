/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzannis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:21:04 by lzannis           #+#    #+#             */
/*   Updated: 2025/02/12 22:59:27 by lzannis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int	main(int arc, char *arv[])
{
	t_window		w_d;

	if (arc != 2 && arc != 4)
	{
		write (2, "Error: choose one of the following arguments: ", 47);
		write (2, "mandelbrot, julia or burning_ship\n", 35);
		return (0);
	}
	ft_innit(&w_d);
	create_window(&w_d);
	if (arc == 2)
		ft_display_name(arv[1], &w_d);
	if (arc == 4)
	{
		if (ft_strcmp(arv[1], "julia") == 0)
		{
			w_d.pt.c1_julia = ft_atof(arv[2]);
			w_d.pt.c2_julia = ft_atof(arv[3]);
			printf("%f\n", w_d.pt.c1_julia);
			printf("%f\n", w_d.pt.c2_julia);
			ft_display_julia(&w_d);
		}
		ft_error(arv[1], &w_d);
	}
	draw_image(&w_d);
	return (0);
}
