/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:21:30 by bargarci          #+#    #+#             */
/*   Updated: 2023/11/23 23:21:35 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include <stdio.h>

void	calculate_magn(t_formula *formula)
{
	double	a;
	double	b;

	a = formula->z_imag * formula->z_imag;
	b = formula->z_real * formula->z_real;
	formula->z_magn = a + b;
}

void	calculate_total(t_formula *formula)
{
	formula->z_real = formula->z_real + formula->c_real;
	formula->z_imag = formula->z_imag + formula->c_imag;
}

void	calculate_z(t_formula *formula)
{
	double	a;
	double	b;
	double	ab;

	a = formula->z_real * formula->z_real;
	b = formula->z_imag * formula->z_imag;
	ab = formula->z_real * formula->z_imag;
	formula->z_imag = ab + ab;
	formula->z_real = a - b;
}

void	mandelbrot(t_fractol *fractol, t_data *img, t_global *global)
{
	t_formula	formula;
	int	i;

	set_formula(fractol, &formula);
	global->formula = formula;
	i = 1;
	while (i < fractol->iters)
	{
		calculate_z(&formula);
		calculate_total(&formula);
		calculate_magn(&formula);
	/*	if (formula.z_magn > 3 && formula.z_magn < 5)
		{
			formula.color = 0x00FF0000;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}*/
		if (formula.z_magn > 5)
		{
			formula.color = 0x000000FF;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}
		formula.color = 0x000000;
		i++;
	}
	my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
}

/*void	leaks(void)
{
	system("leaks fractol");
}*/
int	main(void)
{
	t_data		img;
	double		i;
	t_fractol	fractol;
	t_global	global;
	t_mlx		mlx;

//	atexit(leaks);
	i = 0;
	set_struct(&fractol);
	global.fractol = fractol;
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, 800, 800, "FRACT-OL");
	img.img = mlx_new_image(mlx.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	global.img = img;
	global.mlx = mlx;
	scale_x(&fractol, &img, &global);
	mlx_key_hook(mlx.mlx_win, key_hook_han, &global);
	mlx_mouse_hook(mlx.mlx_win, mouse_move, &global);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, close_hook, &global);
//	mlx_hook(mlx.mlx_win, 6, 0, mouse_move, &global);
	mlx_loop(mlx.mlx);
	return (0);
}
