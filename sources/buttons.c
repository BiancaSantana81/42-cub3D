#include "../includes/cub.h"

void	buttons(t_cub *game, unsigned char key)
{
	if (key == 'l')
	{
		game->player->pa -= 0.1;
		if (game->player->pa < 0)
			game->player->pa += 2 * PI;
		draw_player_direction(game);
	}
	else if (key == 'r')
	{
		game->player->pa += 0.1;
		if (game->player->pa > 2 * PI)
			game->player->pa -= 2 * PI;
		draw_player_direction(game);
	}
}


// void	buttons(t_cub *game, unsigned char key)
// {
// 	if (key == 'left')
// 	{
// 		game->player->pa -= 0.1;
// 		if (game->player->pa < 0)
// 			game->player->pa += 2 * PI;
// 		game->player->pdx = cos(game->player->pa) * 5;
// 		game->player->pdy = sin(game->player->pa) * 5;
// 	}
// 	else if (key == 'right')
// 	{
// 		game->player->pa += 0.1;
// 		if (game->player->pa > 2 * PI)
// 			game->player->pa -= 2 * PI;
// 		game->player->pdx = cos(game->player->pa) * 5;
// 		game->player->pdy = sin(game->player->pa) * 5;
// 	}
	// else if (key == 'w')
	// {
	// 	game->player->px += game->player->pdx;
	// 	game->player->py += game->player->pdy;
	// }
	// else if (key == 's')
	// {
	// 	game->player->px -= game->player->pdx;
	// 	game->player->py -= game->player->pdy;
	// }
