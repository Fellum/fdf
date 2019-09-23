#include "params.h"
#include "matrices.h"

void	draw_line(t_gparams *data, t_point *from, t_point *to);

//void	update_matrix(t_gparams *data)
//{
//	drop_matrix(data->tf_matrix);
//	//add_scaling(data->tf_matrix, data->xy_scale, data->xy_scale, data->z_scale);
//
//	//add_xrotation(data->tf_matrix, data->x_angle);
//	//add_yrotation(data->tf_matrix, data->y_angle);
//}

void	draw_map(t_gparams *data)
{
	int cur_row;
	int cur_coll;
	t_point	**map;

	map = data->map->map;
	cur_row = 0;
	while (cur_row < data->map->rows)
	{
		cur_coll = 0;
		while (cur_coll < data->map->colls - 1)
		{
			draw_line(data, map[cur_row] + cur_coll, map[cur_row] + cur_coll + 1);
			cur_coll++;
		}
		cur_row++;
	}
	cur_coll = 0;
	while (cur_coll < data->map->colls)
	{
		cur_row = 0;
		while (cur_row < data->map->rows - 1)
		{
			draw_line(data, map[cur_row] + cur_coll, map[cur_row + 1] + cur_coll);
			cur_row++;
		}
		cur_coll++;
	}
}
