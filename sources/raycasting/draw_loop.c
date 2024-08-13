#include "../../includes/cub.h"

void	draw_playerview(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	process_input(game);
	draw_background(game);
	update_fps(game);
	draw_rays(game);
}

void	draw_wall(t_dda *ray, t_cub *game, int pixel)
{
	int		wall_height;
	float	line_start_y;
	float	line_end_y;
	//float	texture_step_y;
	//float	texture_start_y;

	wall_height = (HEIGHT / ray->perp_dist);
	line_start_y = (HEIGHT / 2 - wall_height / 2);
	line_end_y = (HEIGHT / 2 + wall_height / 2);
	//texture_step_y = (float)game->walls_image->height / wall_height;
	//texture_start_y = 0;
	//(void)texture_start_y;
	//(void)texture_step_y;
	bresenham_algorithm(game, pixel, line_start_y, pixel, line_end_y);
}

// determinar qual parede desenhar de acordo com norte, sul, leste e oeste
void	sett_wall(t_dda *ray, t_cub*game)
{
	(void)ray;
	(void)game;
	return ;
}
