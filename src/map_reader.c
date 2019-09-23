/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blomo <blomo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 13:31:07 by blomo             #+#    #+#             */
/*   Updated: 2019/09/23 15:58:51 by blomo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_get_next_line.h"
#include "point.h"
#include "params.h"

void		raise_error();

size_t		calc_words(char const *s, char c)
{
	size_t	res;
	size_t	cur;

	cur = 0;
	res = 0;
	while (s[cur])
	{
		while (s[cur] && s[cur] == c)
			cur++;
		if (s[cur])
		{
			res++;
			while (s[cur] && s[cur] != c)
				cur++;
		}
	}
	return (res);
}

void		calc_sizes(char *fname, int *cols, int *rows)
{
	int		fd;
	char	*line;

	if ((fd = open(fname, O_RDONLY)) < 0)
		raise_error();
	if (ft_get_next_line(fd, &line) != GNL_SUCCESS)
		raise_error();
	if (ft_strlen(line) == 0)
	{
		free(line);
		raise_error();
	}
	*cols = calc_words(line, ' ');
	free(line);
	*rows = 1;
	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		free(line);
		(*rows)++;
	}
	close(fd);
}

void		fill_map(char *fname, t_map *res, int cols)
{
	int		fd;
	char	*line;
	int		cur_row;
	int		count;

	if ((fd = open(fname, O_RDONLY)) < 0)
		raise_error();
	cur_row = 0;
	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		count = calc_words(line, ' ');
		if (count != cols)
		{
			free(line);
			free(res);
			raise_error();
		}
		fill_row(res, line, cur_row);
		free(line);
		cur_row++;
	}
	close(fd);
}

t_map		*read_map(char *fname)
{
	t_map	*res;
	int		col_len;
	int		row_len;

	calc_sizes(fname, &col_len, &row_len);
	res = init_map(col_len, row_len);
	fill_map(fname, res, col_len);
	return (res);
}
