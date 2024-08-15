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

	images = mlx_load_png(path);
	if (!images)
		handle_error("Error: mlx_load_png failed");
	return (images);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int y, int x)
{
	int		texture_pos;
	uint8_t	*pixel;

	 if (x < 0 || x >= (int)texture->width || y < 0
	 	|| y >= (int)texture->height)
        return (0);
	texture_pos = y * texture->width + x;
	texture_pos *= texture->bytes_per_pixel;
	pixel = &texture->pixels[texture_pos];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}
