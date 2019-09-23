#include "params.h"
#include "usefull_defs.h"
#include <stdlib.h>

void	draw_map(t_gparams *data);

int	key_press(int keycode, t_gparams *param)
{
	param->kstate[keycode] = 1;
	return (0);
}

int	key_release(int keycode, t_gparams *param)
{
	param->kstate[keycode] = 0;
	return (0);
}

void	apply_keystate(t_gparams *data);

int draw_tick(t_gparams *param)
{
	apply_keystate(param);
	draw_map(param);
	draw_canvas(param->canvas, 0, 0);
	return (0);
}


int	close_event(t_gparams *param)
{
	(void)param;
	exit(0);
}
