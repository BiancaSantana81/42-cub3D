#include "../../includes/cub.h"

void	load_textures(t_cub *game)
{
	game->north = init_images(game->data->no);
	game->south = init_images(game->data->so);
	game->west = init_images(game->data->we);
	game->east = init_images(game->data->ea);
}

mlx_texture_t	*init_images(char *path)
{
	mlx_texture_t	*images;

	images = ft_calloc(sizeof(mlx_texture_t), 1);
	if (!images)
		handle_error("Error: malloc failed");
	images = mlx_load_png(path);
	if (!images)
		handle_error("Error: mlx_load_png failed");
	return (images);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int		texture_pos;
	uint8_t	*pixel;

	texture_pos = y * texture->width + x;
	texture_pos *= texture->bytes_per_pixel;
	pixel = &texture->pixels[texture_pos];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
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
