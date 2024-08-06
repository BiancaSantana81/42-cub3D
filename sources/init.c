#include "../includes/cub.h"

void	init_cub(t_cub *game)
{
	game->mlx = NULL;
	game->data = ft_calloc(1, sizeof(t_data));
	game->player = ft_calloc(1, sizeof(t_player));
	init_player(game);
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

void	init_player(t_cub *game)
{
	game->player->x = 0;
	game->player->y = 0;
	game->player->py = 0;
	game->player->px = 0;
	game->player->pdy = 0;
	game->player->pdx = 0;
	game->player->pa = 0;
}
