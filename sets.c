#include "fractol.h"
#include "libft/libft.h"
#include <stdio.h>

void	set_Mandelbrot(t_fractol *fractol, t_formula *formula)
{
	formula->c_real = fractol->x_real_n;
	formula->c_imag = fractol->y_imag_n;
	formula->z_real = fractol->x_real_n;
	formula->z_imag = fractol->y_imag_n;
}

void	set_Julia(t_fractol *fractol, t_formula *formula, t_global *global)
{
	formula->c_imag = ft_atod(global->arguments.argvs[3]);
	formula->c_real = ft_atod(global->arguments.argvs[2]);
	formula->z_real = fractol->x_real_n;
	formula->z_imag = fractol->y_imag_n;
	formula->z_magn = 0.0;
}

void	set_struct(t_fractol *fractol)
{
	fractol->old_min = 0;
	fractol->old_max = 799;
	fractol->new_min = -4;
	fractol->new_max = 4;
	fractol->x_real_o = 0;
	fractol->y_imag_o = 0;
	fractol->x_real_n = 0;
	fractol->y_imag_n = 0;
	fractol->trans_x = 0.0;
	fractol->trans_y = 0.0;
	fractol->zoom = 1.0;
	fractol->iters = 42;
}

void	set_arguments(char **argv, int argc, t_global *global)
{
	t_arguments arguments;

	arguments.argvs = argv;
	arguments.argc = argc;
	global->arguments = arguments;
}
