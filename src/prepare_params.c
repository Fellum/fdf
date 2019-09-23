/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:36:49 by jleann            #+#    #+#             */
/*   Updated: 2019/09/22 18:36:49 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "params.h"
#include "ft_string.h"
#include "matrices.h"

void		translate_map(t_gparams *params)
{
	int cur_x;
	int cur_y;
	int transx;
	int transy;

	transx = (params->map->colls - 1) / 2;
	transy = (params->map->rows - 1) / 2;
	cur_y = 0;
	while (cur_y < params->map->rows)
	{
		cur_x = 0;
		while (cur_x < params->map->colls)
		{
			params->map->map[cur_y][cur_x].x -= transx;
			params->map->map[cur_y][cur_x].y -= transy;
			cur_x++;
		}
		cur_y++;
	}
}

void	drop_params(t_gparams *data)
{
	data->x_transl = data->width / 2;
	data->y_transl = data->height / 2;
	data->xy_scale = data->width / data->map->colls / 2;
	data->z_scale = 1;
	data->proj_type = ISO_PROJECTION;
	data->x_angle = 0;
	data->y_angle = 0;
	data->z_angle = 0;
}

t_gparams	*prepare_params(t_map *map)
{
	t_gparams	*res;

	res = ft_memalloc(sizeof(t_gparams));
	ft_bzero(res, sizeof(t_gparams));
	ft_bzero(res->kstate, 31);
	res->width = W_WIDTH;
	res->height = W_HEIGHT;
	res->map = map;
	drop_params(res);
	translate_map(res);
	res->tf_matrix = init_matrix();
	return (res);
}
