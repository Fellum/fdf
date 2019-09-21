#include "params.h"
#include "ft_string.h"
#include "matrix_ops.h"

void		translate_map(t_gparams *params)
{
	int cur_x;
	int cur_y;
	int transx;
	int transy;

	transx = (params->map->colls - 1) / 2;
	transy = (params->map->rows - 1) / 2;
	cur_y = 0;
	while (cur_y < params->map->rows)
	{
		cur_x = 0;
		while (cur_x < params->map->colls)
		{
			translate_point(params->map->map[cur_y] + cur_x, -transx, -transy, 0);
			cur_x++;
		}
		cur_y++;
	}
}

t_gparams	*prepare_params(t_map *map)
{
	t_gparams	*res;

	res = ft_memalloc(sizeof(t_gparams));
	ft_bzero(res, sizeof(t_gparams));
	res->width = W_WIDTH;
	res->height = W_HEIGHT;
	res->map = map;
	res->x_transl = res->width / 2;
	res->y_transl = res->height / 2;
	res->xy_scale = res->width / map->colls / 2;
	res->z_scale = 1;
	res->proj_type = ISO_PROJECTION;
	translate_map(res);
	res->tf_matrix = init_matrix();
	return (res);
}