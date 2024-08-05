#include "../includes/cub.h"

void	assing_position(t_cub *game, int start_x, int start_y)
{
	game->player->px = start_x;
	game->player->py = start_y;
	game->player->pdx = cos(game->player->pa) * 5;
	game->player->pdy = sin(game->player->pa) * 5;
}
