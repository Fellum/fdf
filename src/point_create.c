#include "../include/point.h"
#include <stdlib.h>

t_point	*point_create(double x, double y, double z)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}