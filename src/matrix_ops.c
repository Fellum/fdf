/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:30:34 by jleann            #+#    #+#             */
/*   Updated: 2019/09/22 18:30:37 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"
#include <math.h>

void	add_translation(double *matrix, double x, double y, double z)
{
	matrix[12] += x;
	matrix[13] += y;
	matrix[14] += z;
}

void	add_scaling(double *matrix, double x, double y, double z)
{
	matrix[0] *= x;
	matrix[5] *= y;
	matrix[10] *= z;
}

void	add_xrotation(double *matrix, double angle)
{
	if (fabs(matrix[5]) < DOUBLE_DELTA)
		matrix[5] = cos(TO_RAD(angle));
	else
		matrix[5] *= cos(TO_RAD(angle));
	if (fabs(matrix[6]) < DOUBLE_DELTA)
		matrix[6] = -sin(TO_RAD(angle));
	else
		matrix[6] *= -sin(TO_RAD(angle));
	if (fabs(matrix[9]) < DOUBLE_DELTA)
		matrix[9] = sin(TO_RAD(angle));
	else
		matrix[9] *= sin(TO_RAD(angle));
	if (fabs(matrix[10]) < DOUBLE_DELTA)
		matrix[10] = cos(TO_RAD(angle));
	else
		matrix[10] *= cos(TO_RAD(angle));
}

void	add_yrotation(double *matrix, double angle)
{
	matrix[0] = fabs(matrix[0]) < DOUBLE_DELTA ? cos(TO_RAD(angle)) :
			matrix[0] * cos(TO_RAD(angle));
	matrix[2] = fabs(matrix[2]) < DOUBLE_DELTA ? sin(TO_RAD(angle)) :
			matrix[2] * sin(TO_RAD(angle));
	matrix[8] = fabs(matrix[8]) < DOUBLE_DELTA ? -sin(TO_RAD(angle)) :
			matrix[8] * -sin(TO_RAD(angle));
	matrix[10] = fabs(matrix[10]) < DOUBLE_DELTA ? cos(TO_RAD(angle)) :
			matrix[10] * cos(TO_RAD(angle));
}

void	add_zrotation(double *matrix, double angle)
{
	matrix[0] = fabs(matrix[0]) < DOUBLE_DELTA ? cos(TO_RAD(angle)) :
			matrix[0] * cos(TO_RAD(angle));
	matrix[1] = fabs(matrix[1]) < DOUBLE_DELTA ? -sin(TO_RAD(angle)) :
			matrix[1] * -sin(TO_RAD(angle));
	matrix[4] = fabs(matrix[4]) < DOUBLE_DELTA ? sin(TO_RAD(angle)) :
			matrix[4] * sin(TO_RAD(angle));
	matrix[5] = fabs(matrix[5]) < DOUBLE_DELTA ? cos(TO_RAD(angle)) :
			matrix[5] * cos(TO_RAD(angle));
}
