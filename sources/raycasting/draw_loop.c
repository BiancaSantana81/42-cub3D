#include "../../includes/cub.h"

void	draw_playerview(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	draw_background(game);
	draw_rays(game);
}

void	draw_wall(t_dda *ray, t_cub *game, int pixel)
{
	int		wall_height;
	float	line_start_y;
	float	line_end_y;

	wall_height = (HEIGHT / ray->perp_dist);
	line_start_y = (HEIGHT / 2 - wall_height / 2);
	line_end_y = (HEIGHT / 2 + wall_height / 2);
	bresenham_algorithm(game, pixel, line_start_y, pixel, line_end_y);
}
