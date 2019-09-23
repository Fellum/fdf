#ifndef POINT_H
# define POINT_H

# define PI 3.14159265

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

t_point	*point_create(double x, double y, double z);
void	translate_point(t_point *point, double x, double y, double z);
//void	x_rotation(double angle, t_point *point, t_point *around);
//void	y_rotation(double angle, t_point *point, t_point *around);
//void	z_rotation(double angle, t_point *point, t_point *around);

#endif
