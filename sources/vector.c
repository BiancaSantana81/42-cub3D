#include "../includes/cub.h"

t_vector	create_vector(float x, float y)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	return (vector);
}

t_vector	mult_vector(t_vector v, double scalar)
{
	t_vector	vector;

	vector.x = v.x * scalar;
	vector.y = v.y * scalar;
	return (vector);
}

t_vector	add_vector(t_vector v1, t_vector v2)
{
	t_vector	vector;

	vector.x = v1 .x + v2.x;
	vector.y = v1.y + v2.y;
	return (vector);
}

float	mag_vector(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}