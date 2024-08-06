#include "../includes/cub.h"

void	update_pa(t_cub *game)
{
	if (game->data->pov_player == 'N')
		game->player->pa = PI_270;
	else if (game->data->pov_player == 'S')
		game->player->pa = PI_90;
	else if (game->data->pov_player == 'E')
		game->player->pa = 0;
	else if (game->data->pov_player == 'W')
		game->player->pa = PI;
}

void	draw_player_direction(t_cub *game)
{
	int	start_x;
	int	start_y;
	int	size;
	int	offset;

	size = 10;
	offset = BLOCK / 2;
	start_x = game->data->x_player * BLOCK + offset;
	start_y = game->data->y_player * BLOCK + offset;
	//mlx_image_clear(game->line_image, 0x00000000);
	game->player->px = start_x - size / 2;
	game->player->py = start_y - size / 2;
	draw_line(game, 20);
	mlx_image_to_window(game->mlx, game->line_image, 5, 5);
}

void	draw_line(t_cub *game, int length)
{
	int	x1;
	int	y1;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	x1 = game->player->px + cos(game->player->pa) * length;
	y1 = game->player->py + sin(game->player->pa) * length;
	game->player->pdx = fabsf(x1 - game->player->px);
	game->player->pdy = -fabsf(y1 - game->player->py);
	if (game->player->px < x1)
		sx = 1;
	else
		sx = -1;
	if (game->player->py < y1)
		sy = 1;
	else
		sy = -1;
	err = game->player->pdx + game->player->pdy;
	while (1)
	{
		mlx_put_pixel(game->line_image,
			game->player->px, game->player->py, 0xFFFFFFFF);
		if (game->player->px == x1 && game->player->py == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= game->player->pdy)
		{
			err += game->player->pdy;
			game->player->px += sx;
		}
		if (e2 <= game->player->pdx)
		{
			err += game->player->pdx;
			game->player->py += sy;
		}
	}
}
