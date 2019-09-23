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
	t_canvas	*canvas;
	char		kstate[34];
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
}				t_gparams;

t_gparams	*prepare_params(t_map *map);
void		drop_params(t_gparams *data);
t_map			*init_map(int colls, int rows);
void			fill_row(t_map *res, char *line, int cur_row);
void del_split(char **str);
void	raise_error();

# define W_WIDTH 2000
# define W_HEIGHT 1500

#define ISO_PROJECTION 0
#define XY_PROJECTION 1

#endif //FDF_PARAMS_H
