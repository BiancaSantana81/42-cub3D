#include "../../includes/cub.h"

static void	intersection_point(t_dda *ray, t_cub *game, t_wall *wall);
static void	find_texture_position_x(t_dda *ray, t_cub *game, t_wall *wall);
static void	render_wall(t_cub *game, int pixel, t_wall *wall);

void	draw_wall(t_dda *ray, t_cub *game, int pixel)
{
	t_wall	wall;

	game->texture = set_wall(game, ray);
	wall.height = (HEIGHT / ray->perp_dist);
	wall.line_start_y = (HEIGHT / 2 - wall.height / 2);
	wall.line_end_y = (HEIGHT / 2 + wall.height / 2);
	if (wall.line_start_y < 0)
		wall.line_start_y = 0;
	if (wall.line_end_y >= HEIGHT)
		wall.line_end_y = HEIGHT - 1;
	intersection_point(ray, game, &wall);
	find_texture_position_x(ray, game, &wall);
	wall.texture_pos = (wall.line_start_y - HEIGHT / 2 + wall.height / 2)
		* wall.texture_step;
	render_wall(game, pixel, &wall);
}

static void	intersection_point(t_dda *ray, t_cub *game, t_wall *wall)
{
	if (ray->hit_side == 0)
		wall->point_x = game->pos.y + ray->perp_dist * ray->dir.y;
	else
		wall->point_x = game->pos.x + ray->perp_dist * ray->dir.x;
	wall->point_x -= floor(wall->point_x);
}

static void	find_texture_position_x(t_dda *ray, t_cub *game, t_wall *wall)
{
	(void)ray;
	wall->texture_x = (int)(wall->point_x * game->texture->width);
	if ((ray->hit_side == 0 && ray->dir.x < 0)
		|| (ray->hit_side == 1 && ray->dir.y > 0))
		wall->texture_x = game->texture->width - wall->texture_x - 1;
	wall->texture_step = 1.0 * game->texture->height / wall->height;
}

static void	render_wall(t_cub *game, int pixel, t_wall *wall)
{
	int			y;
	int			texture_y;
	uint32_t	color;

	y = wall->line_start_y;
	while (y < wall->line_end_y)
	{
		texture_y = (int)wall->texture_pos;
		if (texture_y < 0)
			texture_y = 0;
		if (texture_y >= (int)game->texture->height)
			texture_y = game->texture->height - 1;
		wall->texture_pos += wall->texture_step;
		color = get_texture_color(game->texture, texture_y, wall->texture_x);
		mlx_put_pixel(game->mlx_image, pixel, y, color);
		y++;
	}
}

mlx_texture_t	*set_wall(t_cub *game, t_dda *ray)
{
	if (ray->hit_side == 1)
	{
		if (ray->step.y < 0)
			return (game->north);
		else
			return (game->south);
	}
	else
	{
		if (ray->step.x < 0)
			return (game->west);
		else
			return (game->east);
	}
	return (NULL);
}
