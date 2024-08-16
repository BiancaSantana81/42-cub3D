#include "../../../includes_bonus/cub_bonus.h"

void	draw_player_square(t_cub *game, int start_x, int start_y, int size)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	end_x;
	uint32_t	end_y;

	end_x = start_x + size;
	end_y = start_y + size;
	y = (uint32_t)start_y;
	while (y < end_y)
	{
		x = (uint32_t)start_x;
		while (x < end_x)
		{
			if (x < game->map_image->width && y < game->map_image->height)
				mlx_put_pixel(game->map_image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
}

void	draw_player(t_cub *game, int scale)
{
	int	start_x;
	int	start_y;
	int	size;
	int	offset;

	size = scale / 2;
	offset = (scale - size) / 2;
	start_x = game->data->x_player * scale + offset;
	start_y = game->data->y_player * scale + offset;
	if (game->map_image)
		draw_player_square(game, start_x, start_y, size);
}
