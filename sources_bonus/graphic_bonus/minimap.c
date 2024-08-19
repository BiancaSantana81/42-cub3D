#include "../../includes_bonus/cub_bonus.h"

static	uint32_t	get_color_for_map_char(char map_char);

void	update_minimap(t_cub *game)
{
	if (game->keys.minimap)
		game->map_image->enabled = true;
	else
		game->map_image->enabled = false;
}

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
	draw_player(game, scale);
	if (game->keys.minimap)
		mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}

void	draw_map(t_cub *game, int scale)
{
	int				i;
	int				j;
	t_square_params	params;

	i = 0;
	while (i < game->data->lines)
	{
		j = 0;
		while (j < game->data->columns && game->data->map[i][j])
		{
			params.start_x = j * scale;
			params.start_y = i * scale;
			params.end_x = params.start_x + scale;
			params.end_y = params.start_y + scale;
			params.color = get_color_for_map_char(game->data->map[i][j]);
			draw_map_square(game, params);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}

static uint32_t	get_color_for_map_char(char map_char)
{
	if (map_char == '1')
		return (0xFF0000FF);
	else if (map_char == '0' || ft_strchr("NSWE", map_char))
		return (0x00FF0000);
	else if (map_char == ' ')
		return (0x000000FF);
	return (0);
}

void	draw_map_square(t_cub *game, t_square_params params)
{
	uint32_t	x;
	uint32_t	y;

	y = params.start_y;
	while (y < params.end_y)
	{
		x = params.start_x;
		while (x < params.end_x)
		{
			if (x < game->map_image->width && y < game->map_image->height)
				mlx_put_pixel(game->map_image, x, y, params.color);
			x++;
		}
		y++;
	}
}
