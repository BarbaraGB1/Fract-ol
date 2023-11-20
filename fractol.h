#ifndef FRACTOL_H
# define FRACTOL_H
# include "unistd.h"
# include <mlx.h>
#include "mlx/mlx.h"

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;
#endif

