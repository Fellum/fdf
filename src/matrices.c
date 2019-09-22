/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:29:19 by jleann            #+#    #+#             */
/*   Updated: 2019/09/22 18:29:21 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	drop_matrix(double *matrix)
{
	int	curx;

	ft_bzero(matrix, sizeof(double) * 16);
	curx = 0;
	while (curx < 4)
	{
		matrix[curx + curx * 4] = 1;
		curx++;
	}
}

double	*init_matrix(void)
{
	double	*res;

	res = malloc(sizeof(double) * 16);
	drop_matrix(res);
	return (res);
}

void	calc_points(double *matrix, double *x, double *y, double *z)
{
	double tmpx;
	double tmpy;
	double tmpz;

	tmpx = matrix[0] * *x - matrix[4] * *y + matrix[8] * *z + matrix[12];
	tmpy = -matrix[1] * *x + matrix[5] * *y - matrix[9] * *z + matrix[13];
	tmpz = matrix[2] * *x - matrix[6] * *y + matrix[10] * *z + matrix[14];
	*x = tmpx;
	*y = tmpy;
	*z = tmpz;
}
