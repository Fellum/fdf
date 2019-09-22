#include "params.h"
#include "usefull_defs.h"
#include <stdlib.h>

char X_DIR;
char Y_DIR;
char Z_DIR;
float ZSC_DIR;
float XYSC_DIR;
char IS_DROP;
char PROJ_TYPE = ISO_PROJECTION;

void	draw_map(t_gparams *data);
void	update_matrix(t_gparams *data);

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
	if (keycode == 18)
		IS_DROP = 1;
	if (keycode == 19)
		PROJ_TYPE = XY_PROJECTION;
	if (keycode == 20)
		PROJ_TYPE = ISO_PROJECTION;
	return ((int)param);
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
	return ((int)param);
}

int draw_tick(t_gparams *param)
{
	if (IS_DROP)
	{
		drop_params(param);
		IS_DROP = 0;
	}
	param->proj_type = PROJ_TYPE;
	param->x_angle += 2 * X_DIR;
	param->y_angle += 2 * Y_DIR;
	param->z_angle += 2 * Z_DIR;
	param->z_scale = ZSC_DIR == 0 ? param->z_scale : param->z_scale * ZSC_DIR;
	param->xy_scale = XYSC_DIR == 0 ? param->xy_scale : param->xy_scale * XYSC_DIR;
	update_matrix(param);
	draw_map(param);
	draw_canvas(param->canvas, 0, 0);
	return (0);
}

int	close_event(void *param)
{
	(void)param;
	exit(0);
}