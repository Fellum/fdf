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
	char		proj_type;
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

#define ISO_PROJECTION 0
#define XY_PROJECTION 1
#define YZ_PROJECTION 2
#define XZ_PROJECTION 3

# define DOUBLE_DELTA 0.000001
#endif //FDF_PARAMS_H
