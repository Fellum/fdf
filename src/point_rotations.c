#include "../include/point.h"
#include <math.h>

#define TO_RAD(a) (a / 180 * PI)

void	x_rotation(double angle, t_point *point, t_point *around)
{
	double	tmp;

	translate_point(point, -around->x, -around->y, -around->z);
	tmp = point->z;
	point->z = -point->y * sin(TO_RAD(angle)) + point->z * cos(TO_RAD(angle));
	point->y = point->y * cos(TO_RAD(angle)) + tmp * sin(TO_RAD(angle));
	translate_point(point, around->x, around->y, around->z);
}

void	y_rotation(double angle, t_point *point, t_point *around)
{
	double	tmp;

	translate_point(point, -around->x, -around->y, -around->z);
	tmp = point->x;
	point->x = point->x * cos(TO_RAD(angle)) + point->z * sin(TO_RAD(angle));
	point->z = -tmp * sin(TO_RAD(angle)) +  point->z * cos(TO_RAD(angle));
	translate_point(point, around->x, around->y, around->z);
}

void	z_rotation(double angle, t_point *point, t_point *around)
{
	double	tmp;

	translate_point(point, -around->x, -around->y, -around->z);
	tmp = point->x;
	point->x = point->x * cos(TO_RAD(angle)) - point->y * sin(TO_RAD(angle));
	point->y = tmp * sin(TO_RAD(angle)) + point->y * cos(TO_RAD(angle));
	translate_point(point, around->x, around->y, around->z);
}