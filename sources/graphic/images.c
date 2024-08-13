#include "../../includes/cub.h"

void	load_textures(t_cub *game)
{
	game->north = init_images(game, game->data->no);
	game->south = init_images(game, game->data->so);
	game->west = init_images(game, game->data->we);
	game->east = init_images(game, game->data->ea);
}

t_images	*init_images(t_cub *game, char *path)
{
	t_images	*images;

	images = ft_calloc(sizeof(t_images), 1);
	if (!images)
		handle_error("Error: malloc failed");
	images->texture = mlx_load_png(path);
	if (!images->texture)
		handle_error("Error: mlx_load_png failed");
	images->img = mlx_texture_to_image(game->mlx, images->texture);
	if (!images->img)
		handle_error("Error: mlx_texture_to_image failed");
	return (images);
}

void	draw_images(t_cub *game)
{
	(void)game;
	//if (mlx_image_to_window(game->mlx, game->north->img, 0, 0))
	//	handle_error("Error: mlx_image_to_window failed");
	//if (mlx_image_to_window(game->mlx, game->south->img, 0, 64))
	//	handle_error("Error: mlx_image_to_window failed");
	//if (mlx_image_to_window(game->mlx, game->west->img, 64, 0))
	//	handle_error("Error: mlx_image_to_window failed");
	//if (mlx_image_to_window(game->mlx, game->east->img, 64, 64))
	//	handle_error("Error: mlx_image_to_window failed");
	//if (mlx_image_to_window(game->mlx, game->player->img, 64, 64))
	//	handle_error("Error: mlx_image_to_window failed");
}
