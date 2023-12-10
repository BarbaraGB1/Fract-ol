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

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel /8));
	*(unsigned int*)dst = color;
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
/* void circle(double a, double b, double r, int points, t_data img)
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
 }*/

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
//	int side_length = 100;

    // Coordenadas de los vértices del triángulo en el centro de la ventana
 //   int center_x = 250, center_y = 250;
    
    /*int x1 = center_x, y1 = center_y - (int)(side_length * sqrt(3) / 2);
    int x2 = center_x + side_length / 2, y2 = y1;
    int x3 = center_x, y3 = center_y + (int)(side_length * sqrt(3) / 2);*/
  //  int x1 = center_x, y1 = center_y;
    //int x2 = center_x / 2, y2 = 480;
    //int x3 = center_x + (center_x / 2) , y3 = 480;
//	int		x;
//	int		y;
	int x1 = 250, y1 = 50;
    int x2 = 50, y2 = 450;
    int x3 = 450, y3 = 450;
	write(1, "HOLA", 4);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "ventana prueba");
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_sierpinski(&img, x1, y1, x2, y2, x3, y3, 19);
//	circle(800.0 / 2, 800.0 / 2, 120, 10000000, img);
	//y = 400;
	//x = 400;
	
/*	printf("x vale: %i\n y vale : %i\n", x , y);
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
	}*/

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}
