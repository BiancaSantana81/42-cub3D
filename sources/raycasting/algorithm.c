#include "../../includes/cub.h"

void	draw_rays(t_cub *game)
{
	int		pixel;
	double	mult;

	pixel = 0;
	while (pixel < WIDTH)
	{
		mult = 2 *(pixel / (double)game->window_width) - 1;
		game->camera_pixel = mult_vector(game->camera_plane, mult);
		game->ray_dir = add_vector(game->dir, game->camera_pixel);
		calculate_delta_distance(game);
		game->map_pos = create_vector(floor(game->pos.x), floor(game->pos.y));
		calculate_distance_to_side(game);
		game->wall_map_pos = copy_vector(game->map_pos);
		game->hit = false;
		dda_algorithm(game);
		draw_wall(game, pixel);
		pixel++;
	}
}

void	calculate_delta_distance(t_cub *game)
{
	if (game->ray_dir.x == 0)
	{
		game->delta_dist.x = 1;
		game->delta_dist.y = 0;
	}
	else
		game->delta_dist.x = fabsf(1 / game->ray_dir.x);
	if (game->ray_dir.y == 0)
	{
		game->delta_dist.x = 0;
		game->delta_dist.y = 1;
	}
	else
		game->delta_dist.y = fabsf(1 / game->ray_dir.y);
}

void	calculate_distance_to_side(t_cub *game)
{
	if (game->ray_dir.x < 0)
	{
		game->dist_to_side_x = (game->pos.x - game->map_pos.x)
			* game->delta_dist.x;
		game->step_x = -1;
	}
	else
	{
		game->dist_to_side_x = (game->map_pos.x + 1 - game->pos.x)
			* game->delta_dist.x;
		game->step_x = 1;
	}
	if (game->ray_dir.y < 0)
	{
		game->dist_to_side_y = (game->pos.y - game->map_pos.y)
			* game->delta_dist.y;
		game->step_y = -1;

	}
	else
	{
		game->dist_to_side_y = (game->map_pos.y + 1 - game->pos.y)
			* game->delta_dist.y;
		game->step_y = 1;
	}
}

// se hitside = 0, bateu na parede na vertical
// se hitside = 1, bateu na parede na horizontal
void	dda_algorithm(t_cub *game)
{
	game->dda_line_side_x = game->dist_to_side_x;
	game->dda_line_side_y = game->dist_to_side_y;
	while (game->hit == false)
	{
		if (game->dda_line_side_x < game->dda_line_side_y)
		{
			game->wall_map_pos.x += game->step_x;
			game->dda_line_side_x += game->delta_dist.x;
			game->hit_side = 0;
		}
		else
		{
			game->wall_map_pos.y += game->step_y;
			game->dda_line_side_y += game->delta_dist.y;
			game->hit_side = 1;
		}
		//verifica se bateu na parede
		//verificar se esta usando x e y corretamente para acessar a matriz
		if (game->data->map[(int)game->wall_map_pos.y / BLOCK]
			[(int)game->wall_map_pos.x / BLOCK] == '1')
			game->hit = true;
	}
	calculate_perpendicular_distance(game);
	
}

void	calculate_perpendicular_distance(t_cub *game)
{
	//float	euclidean_dist_x;
	//float	euclidean_dist_y;

	//euclidean_dist_x =  fabsf(game->wall_map_pos.x - game->pos.x + ((1 - game->step_x) / 2));
	//euclidean_dist_y =  fabsf(game->wall_map_pos.y - game->pos.y + ((1 - game->step_y) / 2));

	if (game->hit_side == 0)
		game->perp_dist = fabsf(game->wall_map_pos.x - game->pos.x + ((1 - game->step_x) / 2)) / game->ray_dir.x;
	else
		game->perp_dist = fabsf(game->wall_map_pos.y - game->pos.y + ((1 - game->step_y) / 2)) / game->ray_dir.y;
}