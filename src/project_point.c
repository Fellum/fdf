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

void	project_point(int *x, int *y, t_point *point, t_gparams *data)
{
	double tmpx;
	double tmpy;
	double tmpz;
	double tmp;

	tmpx = point->x;
	tmpy = point->y;
	tmpz = point->z;
	calc_points(data->tf_matrix, &tmpx, &tmpy, &tmpz);
	tmp = tmpx * cos(TO_RAD(data->z_angle)) - tmpy * sin(TO_RAD(data->z_angle));
	tmpy = tmpx * sin(TO_RAD(data->z_angle)) +
			tmpy * cos(TO_RAD(data->z_angle));
	tmpx = tmp;
	if (data->proj_type == ISO_PROJECTION)
	{
		*x = (int)((tmpx - tmpy) * cos(0.523599));
		*y = (int)(-tmpz + (tmpx + tmpy) * sin(0.523599));
	}
	else if (data->proj_type == XY_PROJECTION)
	{
		*x = (int)tmpx;
		*y = (int)tmpy - tmpz;
	}
	*x = *x + (int)(data->x_transl);
	*y = *y + (int)(data->y_transl);
}
