#ifndef FRACTOL_H
# define FRACTOL_H
# include "unistd.h"
# include <mlx.h>

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
#endif
