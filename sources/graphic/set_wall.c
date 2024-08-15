#include "../../includes/cub.h"

mlx_texture_t	*set_wall(t_cub *game, t_dda *ray)
{
	if (game->hit_side == 0)
	{
		if (ray->dir.y < 0)
			return (game->north);
		else
			return (game->south);
	}
	else
	{
		if (ray->dir.x < 0)
			return (game->west);
		else
			return (game->east);
	}
	return (NULL);
}
