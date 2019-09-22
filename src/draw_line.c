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

#include "point.h"
#include "canvas.h"
#include "params.h"

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

void	project_point(int *x, int *y, t_point *point, t_gparams *data);

void	draw_line(t_gparams *data, t_point *from, t_point *to)
{
	int x1;
	int y1;
	int x2;
	int	y2;

	project_point(&x1, &y1, from, data);
	project_point(&x2, &y2, to, data);

	draw_line_2d(data->canvas, x1, y1, x2, y2, from->color);
}

