#include "../includes/cub.h"

static void	aux_draw_line(t_cub *game, t_line *line);
static void	calculate_line_params(t_cub *game, int length, t_line *line);

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
	offset = BLOCK / 2 - size / 2;
	start_x = game->data->x_player * BLOCK + offset;
	start_y = game->data->y_player * BLOCK + offset;
	game->player->px = start_x;
	game->player->py = start_y;
	draw_line(game, BLOCK * 1);
	draw_plane_line(game, BLOCK * 1);
}

void	draw_line(t_cub *game, int length)
{
	t_line	line;

	clear_line_image(game, game->line_image);
	calculate_line_params(game, length, &line);
	aux_draw_line(game, &line);
}

static void	aux_draw_line(t_cub *game, t_line *line)
{
	int	e2;

	while (1)
	{
		mlx_put_pixel(game->line_image,
			game->player->px, game->player->py, 0xFFFFFFFF);
		if (game->player->px == line->x1 && game->player->py == line->y1)
			break ;
		e2 = 2 * line->err;
		if (e2 >= game->player->pdy)
		{
			line->err += game->player->pdy;
			game->player->px += line->sx;
		}
		if (e2 <= game->player->pdx)
		{
			line->err += game->player->pdx;
			game->player->py += line->sy;
		}
	}
}

static void	calculate_line_params(t_cub *game, int length, t_line *line)
{
	line->x1 = game->player->px + cos(game->player->pa) * length;
	line->y1 = game->player->py + sin(game->player->pa) * length;
	game->player->pdx = fabsf(line->x1 - game->player->px);
	game->player->pdy = -fabsf(line->y1 - game->player->py);
	if (game->player->px < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (game->player->py < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = game->player->pdx + game->player->pdy;
}
