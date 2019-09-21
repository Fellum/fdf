


#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>
#include <math.h>
#include <ft_printf_.h>
#include "matrix_ops.h"


#include "usefull_defs.h"
#include "point.h"
#include "canvas.h"
#include "params.h"

void		draw_line(t_gparams *data, t_point *from, t_point *to);
t_map		*read_map(char *fname);

void	update_matrix(t_gparams *data)
{
	drop_matrix(data->tf_matrix);
	add_scaling(data->tf_matrix, data->xy_scale, data->xy_scale, data->z_scale);

	add_xrotation(data->tf_matrix, data->x_angle);
	add_yrotation(data->tf_matrix, data->y_angle);
	//add_zrotation(data->tf_matrix, data->z_angle);

	//add_translation(data->tf_matrix, data->x_transl, data->y_transl, data->z_transl);
}

void	draw_map(t_canvas *canv, t_gparams *data, int color)
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
//----------------GLOBAL_SHIT---------------
char X_DIR;
char Y_DIR;
char Z_DIR;
float ZSC_DIR;
float XYSC_DIR;
//----------------GLOBAL_SHIT---------------
//----------------EVENTS--------------------

int	key_press(int keycode, void *param)
{
	if (keycode == 0)
		Y_DIR = -1;
	if (keycode == 1)
		X_DIR = 1;
	if (keycode == 2)
		Y_DIR = 1;
	if (keycode == 13)
		X_DIR = -1;
	if (keycode == 12)
		Z_DIR = -1;
	if (keycode == 14)
		Z_DIR = 1;
	if (keycode == 24)
		ZSC_DIR = 1.1;
	if (keycode == 27)
		ZSC_DIR = 0.9;
	if (keycode == 33)
		XYSC_DIR = 1.1;
	if (keycode == 30)
		XYSC_DIR = 0.9;
	return (0);
}

int	key_release(int keycode, void *param)
{
	if (keycode == 0)
		Y_DIR = 0;
	if (keycode == 1)
		X_DIR = 0;
	if (keycode == 2)
		Y_DIR = 0;
	if (keycode == 13)
		X_DIR = 0;
	if (keycode == 12)
		Z_DIR = 0;
	if (keycode == 14)
		Z_DIR = 0;
	if (keycode == 24)
		ZSC_DIR = 0;
	if (keycode == 27)
		ZSC_DIR = 0;
	if (keycode == 33)
		XYSC_DIR = 0;
	if (keycode == 30)
		XYSC_DIR = 0;
}

int mouse_move(int x, int y, void *param)
{
	//printf("%d %d\n", x, y);
	return (0);
}

int mouse_release(int button, int x, int y, void *param)
{
	return (0);
}

int mouse_press(int button, int x, int y, void *param)
{
	return (0);
}

int draw_tick(t_gparams *param)
{
	param->x_angle += 2 * X_DIR;
	param->y_angle += 2 * Y_DIR;
	param->z_angle += 2 * Z_DIR;
	param->z_scale = ZSC_DIR == 0 ? param->z_scale : param->z_scale * ZSC_DIR;
	param->xy_scale = XYSC_DIR == 0 ? param->xy_scale : param->xy_scale * XYSC_DIR;
	update_matrix(param);
	draw_map(param->canvas, param, 0xFFFFFF);
	draw_canvas(param->canvas, 0, 0);
	//setTimeout(200);
	return (0);
}

int	close_event(void *param)
{
	(void)param;
	exit(0);
}

//----------------EVENTS--------------------

void	run_app(t_gparams *data)
{
	data->mlx = mlx_init();
	data->wnd = mlx_new_window(data->mlx, data->width, data->height, "Title");

	data->canvas = init_canvas(data->mlx, data->wnd, data->width, data->height);

	mlx_hook(data->wnd, KEY_PRESS_HOOK, 0, key_press, NULL);
	mlx_hook(data->wnd, KEY_RELEASE_HOOK, 0, key_release, NULL);

	mlx_hook(data->wnd, MOUSE_MOVE_HOOK, 0, mouse_move, NULL);
	mlx_hook(data->wnd, MOUSE_RELEASE_HOOK, 0, mouse_release, NULL);
	mlx_hook(data->wnd, MOUSE_PRESS_HOOK, 0, mouse_press, NULL);

	mlx_hook(data->wnd, EXIT_HOOK, 0, close_event, NULL);
	mlx_loop_hook(data->mlx, draw_tick, data);

	mlx_loop(data->mlx);
}


int main(int argc, char **argv)
{
	t_map *res;
	t_gparams	*params;
	if (argc == 2)
	{
		res = read_map(argv[1]);
		params = prepare_params(res);
		run_app(params);
	}
	return (0);
}