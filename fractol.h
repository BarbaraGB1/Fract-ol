#ifndef FRACTOL_H
# define FRACTOL_H
# include "unistd.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fractol{
	double	old_min;
	double	old_max;
	double	new_min;
	double	new_max;
	double	x_real_o;
	double	y_imag_o;
	double	x_real_n;
	double	y_imag_n;
	double	trans_x;
	double	trans_y;
	double	zoom;
	double	iters;
}	t_fractol;

typedef struct s_formula
{
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	z_magn;
	int		color;
}	t_formula;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;
typedef struct s_global
{
	t_formula	formula;
	t_fractol	fractol;
	t_data		img;
	t_mlx		mlx;
}	t_global;

//  SCALE  //
double	rescale(double i, double new_min, double new_max, double old_min, double old_max);
void	scale_x(t_fractol *fractol, t_data *img, t_global *global);

//  SETS  //
void	set_struct(t_fractol *fractol);
void	set_formula(t_fractol *fractol, t_formula *formula);
void	mandelbrot(t_fractol *fractol, t_data *img, t_global *global);

//  MLX  //
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		key_hook_han(int keycode, t_global *global);
int		mouse_hook_han(int keycode, int x, int y, t_global *global);
int		mouse_move(int keycode, int x, int y, t_global *global);
void	run_zoom(t_global *global, double x_real, double y_imag, double factor_zoom_smooth);
int		close_hook(t_global *global);

#endif
