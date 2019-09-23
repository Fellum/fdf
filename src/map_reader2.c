/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:41:47 by blomo             #+#    #+#             */
/*   Updated: 2019/09/23 15:35:32 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_get_next_line.h"
#include "point.h"
#include "params.h"

t_map		*init_map(int colls, int rows)
{
	t_map	*res;
	int		tmp;

	res = malloc(sizeof(t_map));
	res->colls = colls;
	res->rows = rows;
	res->map = malloc(sizeof(t_point *) * rows);
	tmp = 0;
	while (tmp < rows)
	{
		res->map[tmp] = malloc((sizeof(t_point) * colls));
		tmp++;
	}
	return (res);
}

int			ft_atoi_base(char *str)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	res = 0;
	j = 1;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			res = res + (str[i] - 'A' + 10) * j;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res + (str[i] - 'a' + 10) * j;
		else if (str[i] >= '0' && str[i] <= '9')
			res = res + (str[i] - '0') * j;
		j = j * 16;
		i--;
	}
	return (res);
}

int			colors(char *str)
{
	int		i;

	i = 0;
	if (*str == '0')
		str++;
	else
		return (0);
	if (*str == 'x')
		str++;
	else
		return (0);
	while (str[i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'F') ||
		(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	if (i > 8)
		return (0);
	return (ft_atoi_base(str));
}

int			is_all_digits(char *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	if (str[0] == '-')
	{
		if (str[1] >= '0' && str[1] <= '9')
			i = 2;
		else
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (0xFFFFFF);
	if (str[i] == ',')
	{
		res = colors(str + i + 1);
		return (res);
	}
	else
		return (0);
	return (0xFFFFFF);
}

void		fill_row(t_map *res, char *line, int cur_row)
{
	char	**tmp;
	int		cur;
	int		color;

	tmp = ft_strsplit(line, ' ');
	cur = 0;
	while (tmp[cur])
	{
		if (!(color = is_all_digits(tmp[cur])))
		{
			free(res);
			del_split(tmp);
			raise_error();
		}
		if (cur >= res->colls)
		{
			free(res);
			del_split(tmp);
			raise_error();
		}
		res->map[cur_row][cur].z = ft_atoi(tmp[cur]);
		res->map[cur_row][cur].x = cur;
		res->map[cur_row][cur].y = cur_row;
		res->map[cur_row][cur].color = color;
		cur++;
	}
	del_split(tmp);
}
