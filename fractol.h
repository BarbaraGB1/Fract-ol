#ifndef FRACTOL_H
# define FRACTOL_H
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_mlx;

typedef struct s_fractol{
	// Rango Original
	double	old_min;
	double	old_max;
	// Rango Fractol
	double	new_min;
	double	new_max;
	// Coordenadas X Y
	double	x_real_o;
	double	y_imag_o;
	// Result escala
	double	x_real_n;
	double	y_imag_n;
	// Factor Translación movimiento
	double	trans_x;
	double	trans_y;
	// Factor Zoom
	double	zoom;
	// Número max iteracciones
	double	iters;
}	t_fractol;

typedef struct s_formula
{
	// Parte Real Z
	double	z_real;
	// Parte Imaginaria Z
	double	z_imag;
	// Parte Real C
	double	c_real;
	// Parte Imaginaria C
	double	c_imag;
	// Resultado Magnitud
	double	z_magn;
	// Color pintado
	int		color;
}	t_formula;

typedef struct s_arguments
{
	char	**argvs;
	int		argc;
}	t_arguments;

typedef struct s_global
{
	t_formula	formula;
	t_fractol	fractol;
	t_data		img;
	t_mlx		mlx;
	t_arguments	arguments;
}	t_global;

//  SCALE  //
double	interpolate(double i, double new_min, double new_max, double old_min, double old_max);
void	fractal(t_fractol *fractol, t_data *img, t_global *global);

//  SETS  //
void	set_struct(t_fractol *fractol);
void	set_Mandelbrot(t_fractol *fractol, t_formula *formula);
void	set_Julia(t_fractol *fractol, t_formula *formula, t_global *global);
void	do_formula(t_fractol *fractol, t_data *img, t_global *global);
void	set_arguments(char **argv, int argc, t_global *global);

//  MLX  //
void	my_mlx_pixel_put(t_data *img, int x, int y, int color);
int		key_hook_han(int keycode, t_global *global);
int		mouse_hook_han(int keycode, int x, int y, t_global *global);
int		mouse_move(int keycode, int x, int y, t_global *global);
void	run_zoom(t_global *global, double x_real, double y_imag, double factor_zoom_smooth);
int		close_hook(t_global *global);

#endif
