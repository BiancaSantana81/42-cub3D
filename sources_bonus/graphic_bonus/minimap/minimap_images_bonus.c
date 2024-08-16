#include "../../../includes_bonus/cub_bonus.h"

t_sprite	*load_images(t_cub *game, char *path)
{
	t_sprite	*sprites;

	sprites = ft_calloc(1, sizeof(t_sprite));
	if (!sprites)
		handle_error("Error allocating memory for t_sprite.\n");
	sprites->texture = mlx_load_png(path);
	if (!sprites->texture)
		handle_error("Error loading texture with mlx_load_png.\n");
	sprites->img = mlx_texture_to_image(game->mlx, sprites->texture);
	if (!sprites->img)
		handle_error("Error converting texture to image.\n");
	if (!mlx_resize_image(sprites->img, BLOCK, BLOCK))
		handle_error("Error when resizing the texture image.\n");
	return (sprites);
}

void	images_minimap(t_cub *game)
{
	game->mini_wall = load_images(game, "./textures/wall_minimap.png");
	game->mini_floor = load_images(game, "./textures/floor_minimap.png");
}

int	draw_mini_wall(t_cub *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->mini_wall->img, x, y) < 0)
		handle_error("Error when drawing the wall image on the minimap.\n");
	return (0);
}

int	draw_mini_floor(t_cub *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->mini_floor->img, x, y) < 0)
		handle_error("Error when drawing the floor image on the minimap.\n");
	return (0);
}
