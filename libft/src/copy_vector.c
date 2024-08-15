#include "libft.h"

t_vector	copy_vector(t_vector v)
{
	t_vector	vector;

	vector.x = v.x;
	vector.y = v.y;
	return (vector);
}
