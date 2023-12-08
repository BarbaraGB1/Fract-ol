#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close_hook(t_global *global)
{
	mlx_destroy_image(global->mlx.mlx, global->img.img);
	mlx_destroy_window(global->mlx.mlx, global->mlx.mlx_win);
	exit(EXIT_FAILURE);
}

int	key_hook_han(int keycode, t_global *global)
{
	// MOVE R
	if (keycode == 2)
		global->fractol.trans_x += (0.1 * global->fractol.zoom);
	// MOVE L
	if (keycode == 0)
		global->fractol.trans_x -= (0.1 * global->fractol.zoom);
	// MOVE U
	if (keycode == 13)
		global->fractol.trans_y -= (0.1 * global->fractol.zoom);
	// MOVE D
	if (keycode == 1)
		global->fractol.trans_y += (0.1 * global->fractol.zoom);
	// ZOOM IN
	if (keycode == 126)
		global->fractol.zoom *= 0.9;
	// ZOOM OUT
	if (keycode == 125)
		global->fractol.zoom *= 1.1;
	// PLUS ITER
	if (keycode == 30)
		global->fractol.iters += 1;
	// LESS ITER
	if (keycode == 44)
		global->fractol.iters -= 1;
	// ZOOM ESC
	if (keycode == 53)
		close_hook(global);
	// ZOOM RESTORE
	if (keycode == 15)
		set_struct(&global->fractol);
//	printf("%i\n", keycode);
	fractal(&global->fractol, &global->img, global);
	mlx_put_image_to_window(global->mlx.mlx, global->mlx.mlx_win, global->img.img, 0, 0);
	return (0);
}

/*int	mouse_hook_han(int keycode, int x, int y, t_global *global)
{
	// ZOOM IN MOUSE
	if (keycode == 5)
		global->fractol.zoom *= 0.9;
	// ZOOM OUT MOUSE 
	if (keycode == 4)
		global->fractol.zoom *= 1.1;
	scale_x(&global->fractol, &global->img, global);
	mlx_put_image_to_window(global->mlx.mlx, global->mlx.mlx_win, global->img.img, 0, 0);
	printf("%i\n", keycode);
	printf("%i %i\n", x, y);
	return (0);
}**/

void	run_zoom(t_global *global, double x_real, double y_imag, double factor_zoom_smooth)
{
	double	zoom_x;
	double	zoom_y;
	double	new_zoom;
//	printf("entro en run_zoom\n");

	zoom_x = x_real - global->fractol.trans_x;
	zoom_y = y_imag - global->fractol.trans_y;
	new_zoom = global->fractol.zoom - factor_zoom_smooth;
	global->fractol.trans_x += (zoom_x * 0.70) / 3; 
	global->fractol.trans_y += (zoom_y * 0.70) / 3; 
	global->fractol.zoom += new_zoom * 0.70;
//	printf("nuevo zoom: %f\n", global->fractol.zoom);
}
int	mouse_move(int keycode, int x, int y, t_global *global)
{
	double	factor_zoom_smooth;
	double	x_real;
	double	y_imag;
//	printf("NO HACER CASO%i%i\n", x, y);
//	printf("El keycode es: %d\n", keycode);
	factor_zoom_smooth = 0.0;
	x_real = (interpolate((double)x, global->fractol.new_min, global->fractol.new_max, 0, 799) * global->fractol.zoom) + global->fractol.trans_x;
	y_imag = (interpolate((double)y, global->fractol.new_min, global->fractol.new_max, 0, 799) * global->fractol.zoom) + global->fractol.trans_y;
	if (keycode == 5)
	{
//		printf("Estoy dentro del zoom in\n");
		factor_zoom_smooth = global->fractol.zoom / 0.9;
	}
	else if (keycode == 4)
		factor_zoom_smooth = global->fractol.zoom / 1.1;
	else 
		return (0);
	run_zoom(global, x_real, y_imag, factor_zoom_smooth);
//	printf("nuevo zoom: %f\n", global->fractol.zoom);
	fractal(&global->fractol, &global->img, global);
	mlx_put_image_to_window(global->mlx.mlx, global->mlx.mlx_win, global->img.img, 0, 0);
	return (0);
}
