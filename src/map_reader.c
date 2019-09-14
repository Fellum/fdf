#include <fcntl.h>
#include "ft_get_next_line.h"
#include "point.h"

typedef struct	s_map
{
	t_point	**map;
	int		colls;
	int		rows;
}				t_map;

void	raise_error()
{
	printf("poshol nahoy\n");
	exit(1);
}

int 	is_all_digits(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			return (0);
		str++;
	}
	return (1);
}

size_t	calc_words(char const *s, char c)
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

void	calc_sizes(char *fname, int *cols, int *rows)
{
	int	fd;
	char *line;

	if ((fd = open(fname, O_RDONLY)) < 0)
		raise_error();
	ft_get_next_line(fd, &line);
	*cols = calc_words(line, ' ');
	*rows = 1;
	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
		(*rows)++;
	close(fd);
}

t_map 	*init_map(int colls, int rows)
{
	t_map	*res;
	size_t 	tmp;

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

void	fill_row(t_map *res, char *line, int cur_row)
{
	char **tmp;
	int cur;

	tmp = ft_strsplit(line, ' ');
	cur = 0;
	while (tmp[cur])
	{
		if (!is_all_digits(tmp[cur]))
			raise_error();
		if (cur >= res->colls)
			raise_error();
		res->map[cur_row][cur].z = ft_atoi(tmp[cur]) * 5;
		res->map[cur_row][cur].x = cur * 5;
		res->map[cur_row][cur].y = cur_row * 5;
		res->map[cur_row][cur].color =(int)(res->map[cur_row][cur].z) * 50000;
		cur++;
	}
}


void	fill_map(char *fname, t_map *res)
{
	int	fd;
	char *line;
	int	cur_row;

	if ((fd = open(fname, O_RDONLY)) < 0)
		raise_error();
	cur_row = 0;
	while (ft_get_next_line(fd, &line) == GNL_SUCCESS)
	{
		fill_row(res, line, cur_row);
		free(line);
		cur_row++;
	}
	close(fd);
}

t_map	*read_map(char *fname)
{
	t_map	*res;
	int	col_len;
	int row_len;
	calc_sizes(fname, &col_len, &row_len);
	res = init_map(col_len, row_len);
	fill_map(fname, res);
	return (res);
}