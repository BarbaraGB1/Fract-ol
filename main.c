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
#include <math.h>
#include <stdio.h>

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	rescale(double i, double new_min, double new_max, double old_min, double old_max)
{
	double	new_scale;

	new_scale = ((new_max - new_min) * (i - old_min)) / (old_max - old_min) + new_min;
	return (new_scale);
}

void	set_formula(t_fractol *fractol, t_formula *formula)
{
	formula->c_real = fractol->x_real_n;
	formula->c_imag = fractol->y_imag_n;
	formula->z_real = fractol->x_real_n;
	formula->z_imag = fractol->y_imag_n;
}

double	get_abso(double a)
{
	if (a < 0)
		a = a * -1;
	return (a);
}

void	calculate_magn(t_formula *formula)
{
	double	a;
	double	b;
////	double	c;

	a = formula->z_imag * formula->z_imag;
	b = formula->z_real * formula->z_real;
	formula->z_magn = a + b;
//	printf("Valor magnitud: %f\n", formula->z_magn);
	//formula->z_magn = sqrt(c);
//	printf("Valor magnitud SQRT: %f\n", sqrt(formula->z_magn));
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

void	mandelbrot(t_fractol *fractol, t_data *img)
{
	t_formula	formula;
	set_formula(fractol, &formula);
	int	i;

	i = 1;
	while (i < 42)
	{
	/*	printf("Z REAL ANTES DE FORMULA          ----------------> %f\n", formula.z_real);
		printf("Z IMAG ANTES DE FORMULA          ----------------> %f\n", formula.z_imag);
		printf("                                                  \n");
		printf("                                                  \n");
		printf("     -----------------------------------------    \n");
		printf("     -----------------------------------------    \n");
		printf("                                                  \n");
		printf("                                                  \n");*/
		calculate_z(&formula);
		/*printf("Z REAL DESPUES DE CALCULAR Z     ----------------> %f\n", formula.z_real);
		printf("Z IMAG DESPUES DE CALCULAR Z     ----------------> %f\n", formula.z_imag);
		printf("                                                  \n");
		printf("                                                  \n");
		printf("     -----------------------------------------    \n");
		printf("     -----------------------------------------    \n");
		printf("                                                  \n");
		printf("                                                  \n");*/
		calculate_total(&formula);
		/*printf("Z REAL DESPUES DE CALCULAR Z + C ----------------> %f\n", formula.z_real);
		printf("Z IMAG DESPUES DE CALCULAR Z + C ----------------> %f\n", formula.z_imag);
		printf("                                                  \n");
		printf("                                                  \n");
		printf("     -----------------------------------------    \n");
		printf("     -----------------------------------------    \n");
		printf("                                                  \n");
		printf("                                                  \n");*/
		calculate_magn(&formula);
		/*if (formula.z_magn > 0.10 && formula.z_magn < 3)
 		{
			formula.color = 0xFFFFFF;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}*/
		if (formula.z_magn > 3 && formula.z_magn < 5)
		{
			formula.color = 0x000000FF;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}
		if (formula.z_magn > 5 && formula.z_magn < 20)
		{
			formula.color = 0x00FF0000;
			my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
			return ;
		}
	//	printf("puntos pertenecientes al cojunto: %f\n", formula.z_magn);
		formula.color = 0x000000;
		i++;
	}
	my_mlx_pixel_put(img, fractol->x_real_o, fractol->y_imag_o, formula.color);
}

void	scale_x(t_fractol *fractol, t_data *img)
{
	int	i = 0;
	int	j = 0;

	while (fractol->y_imag_o < 800)
	{
		while (fractol->x_real_o < 800)
		{
			fractol->x_real_n = rescale(fractol->x_real_o, -2, +2, 0, 799);
			fractol->y_imag_n = rescale(fractol->y_imag_o, -2, +2, 0, 799);
		//	printf("X real en %d vuelta\n|%f| ---> |%f|\n", j, fractol->x_real_o, fractol->x_real_n);
		//º	printf("Y imaginario %d vuelta\n|%f|  --->  |%f|\n", i, fractol->y_imag_o, fractol->y_imag_n);
			mandelbrot(fractol , img);
			fractol->x_real_o++;
			j++;
		}
		i++;
		j = 0;
		fractol->x_real_o = 0;
		fractol->y_imag_o++;
	////	fractol->y_imag_n = rescale(fractol->y_imag_o, -2, +2, 0, 799);
	}
}

void	set_struct(t_fractol *fractol)
{
	fractol->old_min = 0;
	fractol->old_max = 799;
	fractol->new_min = -2;
	fractol->new_max = 2;
	fractol->x_real_o = 0;
	fractol->y_imag_o = 0;
	fractol->x_real_n = 0;
	fractol->y_imag_n = 0;
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	double		i;
	t_fractol	fractol;

	i = 0;
	set_struct(&fractol);
	printf("    OLD    ----     NEW   \n");
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "ventana prueba");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	scale_x(&fractol, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
