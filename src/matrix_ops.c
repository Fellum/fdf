#include "ft_string.h"
#include "matrix_ops.h"
#include <math.h>

void	drop_matrix(double *matrix)
{
	int	curx;
	int	cury;

	ft_bzero(matrix,sizeof(double) * 16);
	curx = 0;
	cury = 0;
	while (curx < 4)
		matrix[curx++ + cury++ * 4] = 1;
}

double	*init_matrix()
{
	double	*res;

	res = malloc(sizeof(double) * 16);
	drop_matrix(res);
	return (res);
}

void 	calc_points(double *matrix, double *x, double *y, double *z)
{
	double tmpx;
	double tmpy;
	double tmpz;

	tmpx = matrix[0] * *x - matrix[4] * *y + matrix[8] * *z; //+ matrix[12];
	tmpy = -matrix[1] * *x + matrix[5] * *y - matrix[9] * *z;//+ matrix[13];
	tmpz = matrix[2] * *x - matrix[6] * *y + matrix[10] * *z;//+ matrix[14];
	*x = tmpx;
	*y = tmpy;
	*z = tmpz;
}

void 	add_translation(double *matrix, double x, double y, double z)
{
	matrix[12] += x;
	matrix[13] += y;
	matrix[14] += z;
}

void 	add_scaling(double *matrix, double x, double y, double z)
{
	matrix[0] *= x;
	matrix[5] *= y;
	matrix[10] *= z;
}

void	add_xrotation(double *matrix, double angle)
{
//	matrix[5] *= cos(TO_RAD(angle));
//	matrix[6] *= -sin(TO_RAD(angle));
//	matrix[9] *= sin(TO_RAD(angle));
//	matrix[10] *= cos(TO_RAD(angle));

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
	matrix[0] = fabs(matrix[0]) < DOUBLE_DELTA ? cos(TO_RAD(angle)): matrix[0] * cos(TO_RAD(angle));
	matrix[2] = fabs(matrix[2]) < DOUBLE_DELTA ? sin(TO_RAD(angle)): matrix[2] * sin(TO_RAD(angle));
	matrix[8] = fabs(matrix[8]) < DOUBLE_DELTA ? -sin(TO_RAD(angle)): matrix[8] * -sin(TO_RAD(angle));
	matrix[10] = fabs(matrix[10]) < DOUBLE_DELTA ? cos(TO_RAD(angle)): matrix[10] * cos(TO_RAD(angle));
}

void	add_zrotation(double *matrix, double angle)
{
//	matrix[0] *= cos(TO_RAD(angle));
//	matrix[1] *= -sin(TO_RAD(angle));
//	matrix[4] *= sin(TO_RAD(angle));
//	matrix[5] *= cos(TO_RAD(angle));

	matrix[0] = fabs(matrix[0]) < DOUBLE_DELTA ? cos(TO_RAD(angle)): matrix[0] * cos(TO_RAD(angle));
	matrix[1] = fabs(matrix[1]) < DOUBLE_DELTA ? -sin(TO_RAD(angle)) : matrix[1] * -sin(TO_RAD(angle));
	matrix[4] = fabs(matrix[4]) < DOUBLE_DELTA ? sin(TO_RAD(angle)) : matrix[4] * sin(TO_RAD(angle));
	matrix[5] = fabs(matrix[5]) < DOUBLE_DELTA ? cos(TO_RAD(angle)) : matrix[5] * cos(TO_RAD(angle));
}