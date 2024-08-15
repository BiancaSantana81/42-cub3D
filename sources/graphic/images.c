#include "../../includes/cub.h"

void	load_textures(t_cub *game)
{
	game->north = init_images(game->data->no);
	game->south = init_images(game->data->so);
	game->west = init_images(game->data->we);
	game->east = init_images(game->data->ea);
	game->texture_buffer[0] = game->east;
	game->texture_buffer[1] = game->north;
	game->texture_buffer[2] = game->south;
	game->texture_buffer[3] = game->west;
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

uint32_t	get_texture_color(mlx_texture_t *texture, int y, int x)
{
	int		texture_pos;
	uint8_t	*pixel;

	texture_pos = y * texture->width + x;
	texture_pos *= texture->bytes_per_pixel;
	pixel = &texture->pixels[texture_pos];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

void	read_texture_on_the_map(t_cub *game, t_dda *ray)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < game->texture_buffer)
	{
		while (y < TEXTURE_HEIGHT)
		{
			while (x < TEXTURE_WIDTH)
			{
				print_texture(get_texture_color(game->texture_buffer[i], y, x));
				x++;
			}
			y++;
		}
		i++;
	}
}
