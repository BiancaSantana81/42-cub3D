#include "../includes/cub.h"

void	init_cub(t_cub *game)
{
	game->mlx = NULL;
	game->window_height = 0;
	game->window_width = 0;
	game->frame_time = 0;
	game->data = ft_calloc(1, sizeof(t_data));
	init_data(game);
	get_game(game);
}

void	init_data(t_cub *game)
{
	game->data->size_textures = 0;
	game->data->no = NULL;
	game->data->so = NULL;
	game->data->we = NULL;
	game->data->ea = NULL;
	game->data->map = NULL;
	game->data->y_player = 0;
	game->data->x_player = 0;
	game->data->colors = false;
	game->data->floor = 0;
	game->data->ceiling = 0;
}

void	init_variables_valid(t_validate *valid)
{
	valid->invalid = 0;
	valid->player = 0;
	valid->n = 0;
}
