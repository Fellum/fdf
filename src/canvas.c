/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:05:59 by jleann            #+#    #+#             */
/*   Updated: 2019/09/21 21:06:00 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include "mlx.h"
#include <stdlib.h>
#include "ft_string.h"

t_canvas	*init_canvas(void *mlx, void *window, int width, int height)
{
	t_canvas	*res;

	res = malloc(sizeof(t_canvas));
	res->img_ptr = mlx_new_image(mlx, width, height);
	res->img_data = (int *)mlx_get_data_addr(res->img_ptr, &(res->bpp),
			&(res->size_line), &(res->endian));
	res->mlx_ptr = mlx;
	res->win_ptr = window;
	res->width = width;
	res->height = height;
	return (res);
}

void		put_pixel(t_canvas *canv, int x, int y, int color)
{
	if (x >= 0 && x < canv->width && y >= 0 && y < canv->height)
		(canv->img_data)[x + y * canv->width] = color;
}

void		draw_canvas(t_canvas *canv, int x, int y)
{
	mlx_put_image_to_window(canv->mlx_ptr, canv->win_ptr, canv->img_ptr, x, y);
	ft_bzero(canv->img_data, canv->size_line * canv->height);
}
