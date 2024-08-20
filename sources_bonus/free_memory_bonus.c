#include "../includes_bonus/cub_bonus.h"

void	free_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		ft_free_matrix(data->map);
	if (data)
		free(data);
}

void	free_memory(t_cub *game)
{
	if (game)
		free_data(game->data);
	if (game->north)
		mlx_delete_texture(game->north);
	if (game->south)
		mlx_delete_texture(game->south);
	if (game->west)
		mlx_delete_texture(game->west);
	if (game->east)
		mlx_delete_texture(game->east);
	if (game->player_1)
		free_sprite(game, game->player_1);
	if (game->player_2)
		free_sprite(game, game->player_2);
}

void	free_sprite(t_cub *game, t_images *sprite)
{
	mlx_delete_image(game->mlx, sprite->image);
	mlx_delete_texture(sprite->texture);
	free(sprite);
}
