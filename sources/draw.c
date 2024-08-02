#include "../includes/cub.h"

void	draw_square(t_cub *game, int start_x, int start_y, int size, uint32_t color)
{
	uint32_t x;
	uint32_t y;

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
}

void draw_player_square(t_cub *game)
{
	int	start_x;
	int	start_y;
	int	size; 
	uint32_t color;

	color = 0xFF0000FF;
	start_x = 10; //x onde inicia
	start_y = 10; // y onde inicia
	size = 10; // tamanho do quadrado
	if (game->mlx_image)
		draw_square(game, start_x, start_y, size, color);
}


