#include "../../includes/cub.h"

void	set_wall(t_cub*game, t_images **wall)
{
	if (game->hit_side == 0)
	{
		if (game->dir.y < 0)
			*wall = game->north;
		else if (game->dir.y > 0)
			*wall = game->south;
	}
	else
	{
		if (game->dir.x < 0)
			*wall = game->west;
		else if (game->dir.x > 0)
			*wall = game->east;
	}
}
