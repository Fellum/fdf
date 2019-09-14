


#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>


#include <stdio.h>
#include <math.h>


#include "usefull_defs.h"
#include "point.h"
#include "canvas.h"

void		draw_line(t_canvas *canv, t_point *from, t_point *to, int color);
typedef struct	s_map
{
	t_point	**map;
	int		colls;
	int		rows;
}				t_map;

t_map		*read_map(char *fname);

void	draw_map(t_canvas *canv, t_map *map, color)
{
	int cur_row;
	int cur_coll;

	cur_row = 0;
	while (cur_row < map->rows)
	{
		cur_coll = 0;
		while (cur_coll < map->colls - 1)
		{
			draw_line(canv, map->map[cur_row] + cur_coll, map->map[cur_row] + cur_coll + 1, color);
			cur_coll++;
		}
		cur_row++;
	}
	cur_coll = 0;
	while (cur_coll < map->colls)
	{
		cur_row = 0;
		while (cur_row < map->rows - 1)
		{
			draw_line(canv, map->map[cur_row] + cur_coll, map->map[cur_row + 1] + cur_coll, color);
			cur_row++;
		}
		cur_coll++;
	}

}

void	rotate_map(t_map *map, double angle, t_point *center, void (rot)(double, t_point *, t_point *))
{
	int cur_row;
	int cur_coll;

	cur_row = 0;
	while (cur_row < map->rows)
	{
		cur_coll = 0;
		while (cur_coll < map->colls)
		{
			rot(angle, map->map[cur_row] +cur_coll, center);
			cur_coll++;
		}
		cur_row++;
	}
}

//----------------GLOBAL_SHIT---------------
void *mlx, *window;
t_canvas	*ada;
char X_DIR;
char Y_DIR;
char Z_DIR;
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

int draw_tick(void *param)
{
	t_point	center;

	center.x = 250;
	center.y = 250;
	center.z = 0;

	if (X_DIR)
		rotate_map(param, X_DIR, &center, x_rotation);
	if (Y_DIR)
		rotate_map(param, Y_DIR, &center, y_rotation);
	if (Z_DIR)
		rotate_map(param, Z_DIR, &center, z_rotation);

	draw_map(ada, (t_map *)param, 0xFFFFFF);
	draw_canvas(ada, 0, 0);

	setTimeout(10);
	return (0);
}

int	close_event(void *param)
{
	(void)param;
	exit(0);
}

//----------------EVENTS--------------------

void	run_app(void *data)
{
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "Title");

	ada = init_canvas(mlx, window, 1000, 1000);

	mlx_hook(window, KEY_PRESS_HOOK, 0, key_press, NULL);
	mlx_hook(window, KEY_RELEASE_HOOK, 0, key_release, NULL);

	mlx_hook(window, MOUSE_MOVE_HOOK, 0, mouse_move, NULL);
	mlx_hook(window, MOUSE_RELEASE_HOOK, 0, mouse_release, NULL);
	mlx_hook(window, MOUSE_PRESS_HOOK, 0, mouse_press, NULL);

	mlx_hook(window, EXIT_HOOK, 0, close_event, NULL);
	mlx_loop_hook(mlx, draw_tick, data);

	mlx_loop(mlx);
}


int main(int argc, char **argv)
{
	t_map *res;
	if (argc == 2)
	{
		res = read_map(argv[1]);
		run_app(res);
	}
	return (0);
}