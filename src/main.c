/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:24:06 by jleann            #+#    #+#             */
/*   Updated: 2019/09/22 19:24:08 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "usefull_defs.h"
#include "params.h"
#include "events.h"

void	run_app(t_gparams *data)
{
	data->mlx = mlx_init();
	data->wnd = mlx_new_window(data->mlx, data->width, data->height, "FdF");
	data->canvas = init_canvas(data->mlx, data->wnd, data->width, data->height);
	mlx_hook(data->wnd, KEY_PRESS_HOOK, 0, key_press, data);
	mlx_hook(data->wnd, KEY_RELEASE_HOOK, 0, key_release, data);
	mlx_hook(data->wnd, EXIT_HOOK, 0, close_event, data);
	mlx_loop_hook(data->mlx, draw_tick, data);
	mlx_loop(data->mlx);
}

int		main(int argc, char **argv)
{
	t_gparams	*params;

	if (argc == 2)
	{
		params = prepare_params(read_map(argv[1]));
		run_app(params);
	}
	return (0);
}
