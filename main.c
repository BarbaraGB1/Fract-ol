#include "fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel /8));
	*(unsigned int*)dst = color;
}

double	rescale(double i, double new_min, double new_max, double old_min, double old_max)
{
	double new_scale;

	new_scale = ((new_max - new_min) * (i - old_min)) / (old_max - old_min) + new_min;
	return (new_scale);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	i;
	double	result;

	i = 0;
	write(1, "HOLA\n", 5);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "ventana prueba");
	img.img = mlx_new_image(mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 800)
	{
		result = rescale(i, -2, +2, 0, 799);
		printf("|%f| ---> |%f|\n", i, result);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

	return (0);
}
