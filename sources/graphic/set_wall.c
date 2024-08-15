#include "../../includes/cub.h"

mlx_texture_t	*set_wall(t_cub *game, t_dda *ray)
{
	if (ray->hit_side == 1)
	{
		if (ray->step.y < 0)
			return (game->north);
		else
			return (game->south);
	}
	else
	{
		if (ray->step.x < 0)
			return (game->west);
		else
			return (game->east);
	}
	return (NULL);
}
