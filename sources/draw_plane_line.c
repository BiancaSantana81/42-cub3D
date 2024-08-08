#include "../includes/cub.h"

void	draw_plane_line(t_cub *game, int length)
{
	int		end_x;
	int		end_y;
	int		perp_dx;
	int		perp_dy;
	int		perp_x1;
	int		perp_y1;
	int		perp_x2;
	int		perp_y2;

	// ponto final da linha de direção do jogador.
	end_x = game->player->px + cos(game->player->pa) * length / 16;
	end_y = game->player->py + sin(game->player->pa) * length / 16;
	// vetor perpendicular.
	perp_dx = -sin(game->player->pa) * length / 2;
	perp_dy = cos(game->player->pa) * length / 2;
	// calcula os pontos finais da linha perpendicular.
	perp_x1 = end_x + perp_dx;
	perp_y1 = end_y + perp_dy;
	perp_x2 = end_x - perp_dx;
	perp_y2 = end_y - perp_dy;

	clear_line_image(game, game->plane_line);
	draw_line_segment(game, end_x, end_y, perp_x1, perp_y1);
	draw_line_segment(game, end_x, end_y, perp_x2, perp_y2);
}

void draw_line_segment(t_cub *game, int x0, int y0, int x1, int y1)
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
	int	e2;

	dx = abs(x1 - x0);
	dy = -abs(y1 - y0);
	err = dx + dy;
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	while (1)
	{
		mlx_put_pixel(game->plane_line, x0, y0, 0xFFFFFFFF);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
