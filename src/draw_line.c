/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:58:01 by jleann            #+#    #+#             */
/*   Updated: 2019/04/26 20:58:04 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "../include/point.h"
#include "../include/canvas.h"
#include <math.h>
#include "params.h"
#include "matrix_ops.h"

int	abs(int x)
{
	return (x < 0 ? -x : x);
}

void draw_line_2d(t_canvas *canv, int x1, int y1, int x2, int y2, int color) {
	int deltaX = abs(x2 - x1);
	int deltaY = abs(y2 - y1);
	int signX = x1 < x2 ? 1 : -1;
	int signY = y1 < y2 ? 1 : -1;
	int error = deltaX - deltaY;

	put_pixel(canv, x2, y2, color);
	while(x1 != x2 || y1 != y2)
	{
		put_pixel(canv, x1, y1, color);
		const int error2 = error * 2;
		//
		if(error2 > -deltaY)
		{
			error -= deltaY;
			x1 += signX;
		}
		if(error2 < deltaX)
		{
			error += deltaX;
			y1 += signY;
		}
	}

}

void	calc_2d_point(int *x, int *y, t_point *point, double *matrix, t_gparams *data) {
	double tmpx;
	double tmpy;
	double tmpz;

	double tmp;

	tmpx = point->x;
	tmpy = point->y;
	tmpz = point->z;

	calc_points(matrix, &tmpx, &tmpy, &tmpz);

	tmp = tmpx * cos(TO_RAD(data->z_angle)) - tmpy * sin(TO_RAD(data->z_angle));
	tmpy = tmpx * sin(TO_RAD(data->z_angle)) + tmpy * cos(TO_RAD(data->z_angle));
	tmpx = tmp;

	*x = (int)((tmpx + tmpy) * cos(0.523599)) + 1366 / 2;
	*y = (int)(-tmpz + (tmpx - tmpy) * sin(0.523599)) + 768 / 2;
//
//	*x = tmpx + 1366 / 2;
//	*y = tmpy + 768 / 2;

//	*x = tmpx + 1366 / 2;
//	*y = tmpz + 768 / 2;
//
//	*x = tmpy + 1366 / 2;
//	*y = tmpz + 768 / 2;

}

void	draw_line(t_gparams *data, t_point *from, t_point *to)
{
	int x1;
	int y1;
	int x2;
	int	y2;

	calc_2d_point(&x1, &y1, from, data->tf_matrix, data);
	calc_2d_point(&x2, &y2, to, data->tf_matrix, data);

	draw_line_2d(data->canvas, x1, y1, x2, y2, 0xFFFFFF);
}

