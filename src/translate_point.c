#include "../include/point.h"

void	translate_point(t_point *point, double x, double y, double z)
{
	point->x += x;
	point->y += y;
	point->z += z;
}