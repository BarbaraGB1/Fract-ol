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
#include <stdlib.h>

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

void draw_triangle(t_data *img, int x1, int y1, int x2, int y2, int x3, int y3) 
{
    my_mlx_pixel_put(img, x1, y1, 0xFFFF00);
    my_mlx_pixel_put(img, x2, y2, 0xFF00FF);
    my_mlx_pixel_put(img, x3, y3, 0x00FFFF);
}
void draw_sierpinski(t_data *data, int x1, int y1, int x2, int y2, int x3, int y3, int depth) 
{
    if (depth == 0) {
        // Dibuja el triángulo en la posición actual
        my_mlx_pixel_put(data, x1, y1, 0xFFFF00);
        my_mlx_pixel_put(data, x2, y2, 0xFF00FF);
        my_mlx_pixel_put(data, x3, y3, 0x00FFFF);
    } else {
        // Calcula las coordenadas de los puntos medios de los lados del triángulo
        int mid1_x = (x1 + x2) / 2;
        int mid1_y = (y1 + y2) / 2;
        int mid2_x = (x2 + x3) / 2;
        int mid2_y = (y2 + y3) / 2;
        int mid3_x = (x1 + x3) / 2;
        int mid3_y = (y1 + y3) / 2;

        // Llama recursivamente a la función para los tres subtriángulos
        draw_sierpinski(data, x1, y1, mid1_x, mid1_y, mid3_x, mid3_y, depth - 1);
        draw_sierpinski(data, mid1_x, mid1_y, x2, y2, mid2_x, mid2_y, depth - 1);
        draw_sierpinski(data, mid3_x, mid3_y, mid2_x, mid2_y, x3, y3, depth - 1);
    }
}

void	do_formula(t_fractol *fractol, t_data *img, t_global *global)
{
	int	i;
	i = 1;
	t_formula	formula;
	set_Julia(fractol, &formula, global);
	global->formula = formula;
	while (i < fractol->iters)
	{
		calculate_z(&global->formula);
		calculate_total(&global->formula);
		calculate_magn(&global->formula);
	/*	if (formula.z_magn > 3 && formula.z_magn < 5)
		{
			formula.color = 0x00FF0000;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}*/
		if (global->formula.z_magn > 2)
		{
		//	global->formula.color = 0x00FF0000;
//			global->formula.color = 0xFF0000FF * i / fractol->iters;
//			global->formula.color = 0x000000FF * i / global->formula.z_magn;
		/*	if (formula.c_imag < 0 && (formula.c_real > -2 && formula.c_real < 2))*/
			global->formula.color = 0x0000FF;
			///	formula.color = 0xFF00000 * global->formula.z_magn;
/*			if (formula.c_imag > 0 && (formula.c_real > -2 && formula.c_real < 2) && (formula.c_imag > -2 && formula.c_imag < 2))
				formula.color = 0x000FFFF * (-1 * formula.c_imag) + (-1 * formula.c_real);
			else
				formula.color = 0x0000FF;*/
			//my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, 0x000000);
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, global->formula.color);
			return ;
		}
		i++;
	}
	formula.color = 0xFF00000 * global->formula.z_magn;
	//global->formula.color = 0x000000;
	my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, global->formula.color);
}

void	init_mlx(t_global *global, t_data *img , t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, 800, 800, "FRACT-OL");
	img->img = mlx_new_image(mlx->mlx, 800, 800);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	global->img = *img;
	global->mlx = *mlx;
}

void	mlx_hooks(t_global *global)
{
	mlx_key_hook(global->mlx.mlx_win, key_hook_han, global);
	mlx_mouse_hook(global->mlx.mlx_win, mouse_move, global);
}
/*void	leaks(void) 
{
	system("leaks fractol");
}*/
int	main(int argc, char **argv)
{
	t_data		img;
	t_fractol	fractol;
	t_global	global;
	t_mlx		mlx;

//	atexit(leaks);
	//set_arguments(argv, argc, &global);
	//set_struct(&fractol);
	init_mlx(&global, &img, &mlx);	
/*	if ((argc > 1) && !ft_strncmp(argv[1] , "Julia", 5) && ft_strlen(argv[1]) == 5)
	{
		printf("estoy en julia");
		if (argc != 4)
			exit(EXIT_FAILURE);
		else
		set_Julia(&fractol, &formula ,argv);
	}
	else
		set_Mandelbrot(&fractol, &formula);*/
	global.fractol = fractol;
	fractal(&fractol, &img, &global);
	mlx_hooks(&global);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, img.img, 0, 0);
	mlx_hook(mlx.mlx_win, 17, 0, close_hook, &global);
	mlx_loop(mlx.mlx);
	return (0);
}
