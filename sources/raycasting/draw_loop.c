#include "../../includes/cub.h"

void	draw(t_cub *game)
{
	draw_background(game);
	setup(game);
	draw_rays(game);
}

void	draw_wall(t_cub *game, int pixel)
{
	int	line_start_y;
	int	line_end_y;

	game->wall_height = (int)(HEIGHT / game->perp_dist);
	line_start_y = (int)(HEIGHT / 2 - game->wall_height / 2);
	line_end_y = (int)(HEIGHT / 2 + game->wall_height / 2);
	bresenham_algorithm(game, pixel, line_start_y, pixel, line_end_y);
}