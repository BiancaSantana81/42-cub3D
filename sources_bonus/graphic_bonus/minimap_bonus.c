#include "../../includes_bonus/cub_bonus.h"

void	draw_minimap(void *param)
{
	t_cub	*game;
	int		scale;

	game = param;
	if (game->data->lines > game->data->columns)
		scale = MINI_HEIGHT / game->data->lines;
	else
		scale = MINI_WIDTH / game->data->columns;
	draw_map(game, scale);
}

void	draw_map_square(t_cub *game, int start_x, int start_y, int scale, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	end_x;
	uint32_t	end_y;

	end_x = start_x + scale;
	end_y = start_y + scale;
	y = (uint32_t)start_y;
	while (y < end_y)
	{
		x = (uint32_t)start_x;
		while (x < end_x)
		{
			if (x < game->map_image->width && y < game->map_image->height)
				mlx_put_pixel(game->map_image, x, y, color);
			x++;
		}
		y++;
	}
}

t_sprite	*load_images(t_cub *game, char *path)
{
	t_sprite	*sprites;

	sprites = ft_calloc(1, sizeof(t_sprite));
	if (!sprites)
		handle_error("Erro ao alocar memória para t_sprite.\n");
	sprites->texture = mlx_load_png(path);
	if (!sprites->texture)
		handle_error("Erro ao carregar a textura com mlx_load_png.\n");
	sprites->img = mlx_texture_to_image(game->mlx, sprites->texture);
	if (!sprites->img)
		handle_error("Erro ao converter a textura para imagem.\n");
	if (!mlx_resize_image(sprites->img, BLOCK, BLOCK))
		handle_error("Erro ao redimensionar a imagem da textura.\n");
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
	{
		handle_error("Erro ao desenhar a imagem da parede no minimapa.\n");
		return (-1);
	}
	return (0);
}

int	draw_mini_floor(t_cub *game, int x, int y)
{
	if (mlx_image_to_window(game->mlx,
			game->mini_floor->img, x * BLOCK, y * BLOCK) < 0)
	{
		handle_error("Erro ao desenhar a imagem do chão no minimapa.\n");
		return (-1);
	}
	return (0);
}

void	draw_map(t_cub *game, int scale)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;

	i = 0;
	while (i < game->data->lines)
	{
		j = 0;
		while (j < game->data->columns && game->data->map[i][j])
		{
			start_x = j * scale;
			start_y = i * scale;
			if (game->data->map[i][j] == '1')
				draw_mini_wall(game, start_x, start_y);
			else if (game->data->map[i][j] == '0')
				draw_map_square(game, start_x, start_y, scale, 0xFF9370DB);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}
