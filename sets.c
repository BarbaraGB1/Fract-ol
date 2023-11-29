#include "fractol.h"
#include <stdio.h>

void	set_formula(t_fractol *fractol, t_formula *formula)
{
	formula->c_real = fractol->x_real_n;
	formula->c_imag = fractol->y_imag_n;
	formula->z_real = fractol->x_real_n;
	formula->z_imag = fractol->y_imag_n;
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
	fractol->trans_x = 0.0;
	fractol->trans_y = 0.0;
	fractol->zoom = 3.0;
	fractol->iters = 42;
}
