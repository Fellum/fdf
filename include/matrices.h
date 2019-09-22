//
// Created by Jasper Leann on 17/09/2019.
//

#ifndef FDF_MATRICES_H
#define FDF_MATRICES_H

# define PI 3.14159265
#define TO_RAD(a) (a / 180 * PI)
#define DOUBLE_DELTA 0.000000001
void 	calc_points(double *matrix, double *x, double *y, double *z);
void 	add_translation(double *matrix, double x, double y, double z);
void 	add_scaling(double *matrix, double x, double y, double z);
void 	add_xrotation(double *matrix, double angle);
void 	add_yrotation(double *matrix, double angle);
void 	add_zrotation(double *matrix, double angle);
void	drop_matrix(double *matrix);
double	*init_matrix();


#endif //FDF_MATRICES_H
