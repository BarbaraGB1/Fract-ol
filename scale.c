#include "fractol.h"
#include <stdio.h>

double	rescale(double i, double new_min, double new_max, double old_min, double old_max)
{
	double	new_scale;

	new_scale = ((new_max - new_min) * (i - old_min)) / (old_max - old_min) + new_min;
	return (new_scale);
}

void	scale_x(t_fractol *fractol, t_data *img, t_global *global)
{
//	printf("Entro dentro de scale_x\n");
	fractol->y_imag_o = 0;
	while (fractol->y_imag_o < 800)
	{
		while (fractol->x_real_o < 800)
		{
			fractol->x_real_n = (rescale(fractol->x_real_o, fractol->new_min, fractol->new_max, 0, 799) * fractol->zoom) + fractol->trans_x;
			fractol->y_imag_n = (rescale(fractol->y_imag_o, fractol->new_min, fractol->new_max, 0, 799) * fractol->zoom) + fractol->trans_y;
			mandelbrot(fractol, img, global);
			fractol->x_real_o++;
		}
		fractol->x_real_o = 0;
		fractol->y_imag_o++;
	}
}
