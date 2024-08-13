#include "../../includes/cub.h"

int	set_direction(float dir)
{
	if (dir < 0)
		return (-1);
	return (1);
}

void	draw_rays(t_cub *game)
{
	t_dda	ray;
	int		pixel;

	pixel = 0;
	while (pixel < WIDTH)
	{
		ray.plane_multiplier = 2 * pixel / (float)WIDTH - 1;
		ray.camera_pixel = mult_vector(game->camera_plane, ray.plane_multiplier);
		ray.dir = add_vector(game->dir, ray.camera_pixel);
		ray.step.x = set_direction(ray.dir.x);
		ray.step.y = set_direction(ray.dir.y);
		calculate_delta_distance(&ray);
		calculate_distance_to_side(&ray, game);
		dda_algorithm(&ray, game);
		draw_wall(&ray, game, pixel);
		pixel++;
	}
}

void	calculate_delta_distance(t_dda *ray)
{
	if (ray->dir.x == 0)
	{
		ray->delta_dist.x = 1;
		ray->delta_dist.y = 0;
	}
	else
		ray->delta_dist.x = fabsf(1 / ray->dir.x);
	if (ray->dir.y == 0)
	{
		ray->delta_dist.x = 0;
		ray->delta_dist.y = 1;
	}
	else
		ray->delta_dist.y = fabsf(1 / ray->dir.y);
}

void	calculate_distance_to_side(t_dda *ray, t_cub *game)
{
	ray->map.x = game->pos.x;
	ray->map.y = game->pos.y;

	if (ray->dir.x < 0)
		ray->dist_side.x = (game->pos.x - ray->map.x) * ray->delta_dist.x;
	else
	{
		ray->dist_side.x = (ray->map.x + 1.0 - game->pos.x)
			* ray->delta_dist.x;
	}
	if (ray->dir.y < 0)
		ray->dist_side.y = (game->pos.y - ray->map.y) * ray->delta_dist.y;
	else
	{
		ray->dist_side.y = (ray->map.y + 1.0 - game->pos.y)
			* ray->delta_dist.y;
	}
}

void	dda_algorithm(t_dda *ray, t_cub *game)
{
	while (game->data->map[ray->map.y][ray->map.x] != '1')
	{
		if (ray->dist_side.x < ray->dist_side.y)
		{
			ray->dist_side.x += ray->delta_dist.x;
			ray->map.x += ray->step.x;
			ray->hit_side = 0;
			game->hit_side = 0;
		}
		else
		{
			ray->dist_side.y += ray->delta_dist.y;
			ray->map.y += ray->step.y;
			ray->hit_side = 1;
			game->hit_side = 1;
		}
	}
	if (ray->hit_side == 0)
		ray->perp_dist = ray->dist_side.x - ray->delta_dist.x; 
	else
		ray->perp_dist = ray->dist_side.y - ray->delta_dist.y;
}