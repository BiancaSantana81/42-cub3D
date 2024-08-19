#include "../../includes_bonus/cub_bonus.h"

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

void	move_player_on_minimap(t_cub *game, int scale)
{
	int	new_x;
	int	new_y;
	int	move_speed;

	(void)scale;
	new_x = game->data->x_player;
	new_y = game->data->y_player;
	move_speed = 1;
	if (game->keys.w)
		new_y -= move_speed;
	else if (game->keys.s)
		new_y += move_speed;
	else if (game->keys.a)
		new_x -= move_speed;
	else if (game->keys.d)
		new_x += move_speed;
	if (can_move_to(game, new_x, new_y))
	{
		game->data->x_player = new_x;
		game->data->y_player = new_y;
	}
}
