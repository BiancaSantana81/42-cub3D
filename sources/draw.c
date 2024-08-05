#include "../includes/cub.h"

void	draw_square(t_cub *game, int start_x, int start_y, int size)
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
			if (x < game->mlx_image->width && y < game->mlx_image->height)
				mlx_put_pixel(game->mlx_image, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
}

void	draw_player_square(t_cub *game)
{
	int	start_x;
	int	start_y;
	int	size;
	int	offset;

	size = 10;
	offset = BLOCK / 2 - (size / 2);
	start_x = game->data->x_player * BLOCK + offset;
	start_y = game->data->y_player * BLOCK + offset;
	if (game->mlx_image)
		draw_square(game, start_x, start_y, size);
}

void	draw_map(t_cub *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->data->lines)
	{
		j = 0;
		while (j < game->data->columns)
		{
			if (game->data->map[i][j] == '1')
				draw_map_square(game, j * BLOCK, i * BLOCK, 0x008A2BE2);
			else if (game->data->map[i][j] == '0'
				|| ft_strchr("NSWE", game->data->map[i][j]))
				draw_map_square(game, j * BLOCK, i * BLOCK, 0xFF9370DB);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}

void	draw_map_square(t_cub *game, int start_x, int start_y, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	y = (uint32_t)start_y;
	while (y < (uint32_t)start_y + BLOCK - 1)
	{
		x = (uint32_t)start_x;
		while (x < (uint32_t)start_x + BLOCK - 1)
		{
			if (x < game->map_image->width && y < game->map_image->height)
				mlx_put_pixel(game->map_image, x, y, color);
			x++;
		}
		y++;
	}
}
