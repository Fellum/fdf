/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:27:22 by jleann            #+#    #+#             */
/*   Updated: 2019/09/21 21:27:24 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"
#include "matrices.h"
#include "params.h"
#include <math.h>


void	x_rotation(double angle, double *x, double *y, double *z)
{
	double	tmp;

	tmp = *z;
	*z = -*y * sin(TO_RAD(angle)) + *z * cos(TO_RAD(angle));
	*y = *y * cos(TO_RAD(angle)) + tmp * sin(TO_RAD(angle));
}

void	y_rotation(double angle, double *x, double *y, double *z)
{
	double	tmp;

	tmp = *x;
	*x = *x * cos(TO_RAD(angle)) + *z * sin(TO_RAD(angle));
	*z = -tmp * sin(TO_RAD(angle)) +  *z * cos(TO_RAD(angle));
}

void	z_rotation(double angle, double *x, double *y, double *z)
{
	double	tmp;

	tmp = *x;
	*x = *x * cos(TO_RAD(angle)) - *y * sin(TO_RAD(angle));
	*y = tmp * sin(TO_RAD(angle)) + *y * cos(TO_RAD(angle));
}

void	project_point(int *x, int *y, t_point *point, t_gparams *data)
{
	double tmpx;
	double tmpy;
	double tmpz;

	tmpx = point->x;
	tmpy = point->y;
	tmpz = point->z;
	calc_points(data->tf_matrix, &tmpx, &tmpy, &tmpz);

	x_rotation(data->x_angle, &tmpx, &tmpy, &tmpz);
	y_rotation(data->y_angle, &tmpx, &tmpy, &tmpz);
	z_rotation(data->z_angle, &tmpx, &tmpy, &tmpz);
	tmpx *= data->xy_scale;
	tmpy *= data->xy_scale;
	tmpz *= data->z_scale;
	if (data->proj_type == ISO_PROJECTION)
	{
		*x = (int)((tmpx - tmpy) * cos(0.523599));
		*y = (int)(-tmpz + (tmpx + tmpy) * sin(0.523599));
	}
	else if (data->proj_type == XY_PROJECTION)
	{
		*x = (int)tmpx;
		*y = (int)(tmpy - tmpz);
	}
	*x = *x + (int)(data->x_transl);
	*y = *y + (int)(data->y_transl);
}
