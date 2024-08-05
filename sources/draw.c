#include "../includes/cub.h"

static void	draw_map_square(t_cub *game,
				int start_x, int start_y, int size, uint32_t color);

void	draw_square(t_cub *game,
	int start_x, int start_y, int size, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	y = (uint32_t)start_y;
	while (y < (uint32_t)start_y + size)
	{
		x = (uint32_t)start_x;
		while (x < (uint32_t)start_x + size)
		{
			if (x < game->mlx_image->width && y < game->mlx_image->height)
				mlx_put_pixel(game->mlx_image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
}

void	draw_player_square(t_cub *game)
{
	int			start_x;
	int			start_y;
	int			size;
	uint32_t	color;

	color = 0xFF0000FF;
	start_x = 10; //x onde inicia
	start_y = 10; // y onde inicia
	size = 10; // tamanho do quadrado
	if (game->mlx_image)
		draw_square(game, start_x, start_y, size, color);
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
				draw_map_square(game, j * BLOCK, i * BLOCK, BLOCK, 0x00FFFFFF);
			else if (game->data->map[i][j] == '0')
				draw_map_square(game, j * BLOCK, i * BLOCK, BLOCK, 0x00000000);
			j++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->map_image, 0, 0);
}

static void	draw_map_square(t_cub *game,
	int start_x, int start_y, int size, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	y = (uint32_t)start_y;
	while (y < (uint32_t)start_y + size)
	{
		x = (uint32_t)start_x;
		while (x < (uint32_t)start_x + size)
		{
			if (x < game->map_image->width && y < game->map_image->height)
				mlx_put_pixel(game->map_image, x, y, color);
			x++;
		}
		y++;
	}
}
