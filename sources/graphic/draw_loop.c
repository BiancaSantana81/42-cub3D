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
	int			y;
	int			wall_height;
	float		line_start_y;
	float		line_end_y;

	wall_height = (HEIGHT / ray->perp_dist);
	line_start_y = (HEIGHT / 2 - wall_height / 2);
	line_end_y = (HEIGHT / 2 + wall_height / 2);

	y = line_start_y;
	while (y < game->texture_buffer)
	{
		while (i < line_end_y)
		{
			while (x < TEXTURE_WIDTH)
			{
				print_texture(get_texture_color(game->texture_buffer[i], y, x));
				x++;
			}
			y++;
		}
		y++;
	}
	//bresenham_algorithm(game, pixel, line_start_y, pixel, line_end_y);
}
