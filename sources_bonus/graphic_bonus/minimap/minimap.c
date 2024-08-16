#include "../../../includes_bonus/cub_bonus.h"

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
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
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
				draw_map_square(game, start_x, start_y, scale, 0xFF0000FF);
			else if (game->data->map[i][j] == '0'
				|| ft_strchr("NSWE", game->data->map[i][j]))
				draw_map_square(game, start_x, start_y, scale, 0x00FF00FF);
			else if (game->data->map[i][j] == ' ')
				draw_map_square(game, start_x, start_y, scale, 0x000000FF);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}


void	draw_map_square(t_cub *game,
	int start_x, int start_y, int scale, uint32_t color)
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
