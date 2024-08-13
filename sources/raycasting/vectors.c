#include "../../includes/cub.h"

static void define_initial_plane(t_cub *game)
{
	if (game->data->pov_player == 'N')
	{
		game->dir = create_vector(0, -1);
		game->camera_plane = create_vector(0.66, 0);
	}
	else if (game->data->pov_player == 'S')
	{
		game->dir = create_vector(0, 1);
		game->camera_plane = create_vector(-0.66, 0);
	}
	else if (game->data->pov_player == 'W')
	{
		game->dir = create_vector(-1, 0);
		game->camera_plane = create_vector(0, -0.66);
	}
	else if (game->data->pov_player == 'E')
	{
		game->dir = create_vector(1, 0);
		game->camera_plane = create_vector(0, 0.66);
	}
}

void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player,
			game->data->y_player);
	define_initial_plane(game);
}
