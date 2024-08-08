#include "../includes/cub.h"

static void	setup(t_cub *game);
static void	calculate_dist_to_side(t_cub *game);

void	draw(t_cub *game)
{
	draw_background(game);
	setup(game);
	draw_rays(game);
}

static void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player * (BLOCK / 2),
			game->data->y_player * (BLOCK / 2));
	game->dir = create_vector(-1, 0);
	game->camera_plane = create_vector(0, 0.66);
}

void	draw_rays(t_cub *game)
{
	int		pixel;
	double	mult;

	pixel = 0;
	while ((uint32_t)pixel < game->window_width)
	{
		mult = 2 *(pixel / (double)game->window_width) - 1;
		game->camera_pixel = mult_vector(game->camera_plane, mult);
		game->ray_dir = add_vector(game->dir, game->camera_pixel);
		game->delta_dist.x = mag_vector(game->ray_dir) / game->ray_dir.x;
		game->delta_dist.y = mag_vector(game->ray_dir) / game->ray_dir.y;
		game->map_pos = create_vector(floor(game->pos.x), floor(game->pos.y));
		calculate_dist_to_side(game);
		pixel++;
	}
}

static void	calculate_dist_to_side(t_cub *game)
{
	if (game->ray_dir.x < 0)
		game->dist_to_side_x = (game->pos.x - game->map_pos.x)
			* game->delta_dist.x;
	else
		game->dist_to_side_x = (game->map_pos.x + 1 - game->pos.x)
			* game->delta_dist.x;
	if (game->ray_dir.y < 0)
		game->dist_to_side_y = (game->pos.y - game->map_pos.y)
			* game->delta_dist.y;
	else
		game->dist_to_side_y = (game->map_pos.y + 1 - game->pos.y)
			* game->delta_dist.y;
}
