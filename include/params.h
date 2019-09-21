//
// Created by Jasper Leann on 17/09/2019.
//

#ifndef FDF_PARAMS_H
#define FDF_PARAMS_H

#include "point.h"
#include "canvas.h"

typedef struct	s_map
{
	t_point	**map;
	t_point center;
	int		colls;
	int		rows;
}				t_map;

typedef struct	s_gparams
{
	void		*mlx;
	void		*wnd;
	t_map		*map;
	int			height;
	int 		width;
	double 		x_angle;
	double	 	y_angle;
	double 		z_angle;
	double 		x_transl;
	double 		y_transl;
	double 		z_transl;
	double 		xy_scale;
	double 		z_scale;
	double 		*tf_matrix;
	t_canvas	*canvas;
}				t_gparams;

t_gparams	*prepare_params(t_map *map);


# define W_WIDTH 1366
# define W_HEIGHT 768
# define DOUBLE_DELTA 0.000001
#endif //FDF_PARAMS_H
