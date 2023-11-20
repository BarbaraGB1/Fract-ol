/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bargarci <bargarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:15:04 by bargarci          #+#    #+#             */
/*   Updated: 2023/11/16 20:15:08 by bargarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx/mlx.h"
#include <stdio.h>
#include <math.h>

/*void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

 void circle(double a, double b, double r, int points, t_data img)
 {
 	int	i;
 	double x;
 	double y;
 	double ang;

	i = 0;
	while (i < points)
 	{
		ang = 2 * M_PI * i / points;
		x = a + r * cos(ang);
		y = b + r * sin(ang);
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		i++;
		if (i == points)
		{
			i = 0;
			r--;
			if (r == 0)
			break ;
		}
 	}
 }

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
//	int		x;
//	int		y;
	write(1, "HOLA", 4);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "ventana prueba");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	circle(800.0 / 2, 800.0 / 2, 120, 10000000, img);
	//y = 400;
	//x = 400;
	
	printf("x vale: %i\n y vale : %i\n", x , y);
	while(x != 1200 && y != 1200)
	{
		while (x != 1200)
		{
			my_mlx_pixel_put(&img, x/2, y/2, 0x00FFFFFF);
			x++;
		}
		y = 1200;
		x = 400;
		while (x != 1200)
		{
			my_mlx_pixel_put(&img, x/2, y/2, 0x00FFFFFF);
			x++;
		}
		x = 400;
		y = 400;
		while (y != 1200)
		{
			my_mlx_pixel_put(&img, x/2, y/2, 0x00FFFFFF);
			y++;
		}
		y = 400;
		x = 1200;
		while (y != 1200)
		{
			my_mlx_pixel_put(&img, x/2, y/2, 0x00FFFFFF);
			y++;
		}

	}*/
	/*while(x != 1200 && y != 1200)
	{
		while(x != 1200)
		{
			my_mlx_pixel_put(&img, x/2, y/2, 0x00FFFFFF);
			x++;
		}
		y++;
		x = 400;
	}*/
	//my_mlx_pixel_put(&img, 400/2, 800/2, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 800/2, 400/2, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 400/2, 400/2, 0x00FFFFFF);
//	my_mlx_pixel_put(&img, 1200/2, 400/2, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 1200/2, 1200/2, 0x00FFFFFF);
//	my_mlx_pixel_put(&img, 400/2, 1200/2, 0x00FFFFFF);
	//my_mlx_pixel_put(&img, 1200/2, 800/2, 0x00FFFFFF);
//	my_mlx_pixel_put(&img, 800/2, 1200/2, 0x00FFFFFF);*/
/*	int i = 0;
	while (i < 2)
	{
		while (x < 1200)
			my_mlx_pixel_put(&img, x++ / 2, y / 2, 0x00FF0000);
		x = 400;
		y = 1200;
		i++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}*/
