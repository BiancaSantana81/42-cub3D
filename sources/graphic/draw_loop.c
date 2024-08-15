#include "../../includes/cub.h"

static void	calculate_wall_params(t_dda *ray, t_cub *game, t_wall *wall);
static void	render_wall(t_cub *game, int pixel, t_wall *wall);

void	draw_playerview(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	process_input(game);
	draw_background(game);
	update_fps(game);
	draw_rays(game);
}

static void	calculate_wall_params(t_dda *ray, t_cub *game, t_wall *wall)
{
	int		wall_height;
	float	wall_hit_x;

	wall_height = (HEIGHT / ray->perp_dist);
	wall->line_start_y = (HEIGHT / 2 - wall_height / 2);
	wall->line_end_y = (HEIGHT / 2 + wall_height / 2);
	if (wall->line_start_y < 0)
		wall->line_start_y = 0;
	if (wall->line_end_y >= HEIGHT)
		wall->line_end_y = HEIGHT - 1;
	if (ray->hit_side == 0)
		wall_hit_x = game->pos.y + ray->perp_dist * ray->dir.y;
	else
		wall_hit_x = game->pos.x + ray->perp_dist * ray->dir.x;
	wall_hit_x -= floor(wall_hit_x);
	wall->texture_x = (int)(wall_hit_x * game->texture->width);
	if ((ray->hit_side == 0 && ray->dir.x > 0)
		|| (ray->hit_side == 1 && ray->dir.y < 0))
		wall->texture_x = game->texture->width - wall->texture_x - 1;
	wall->tex_step = 1.0 * game->texture->height / wall_height;
	wall->tex_pos = (wall->line_start_y
			- HEIGHT / 2 + wall_height / 2) * wall->tex_step;
}

static void	render_wall(t_cub *game, int pixel, t_wall *wall)
{
	int			y;
	int			texture_y;
	uint32_t	color;

	y = wall->line_start_y;
	while (y < wall->line_end_y)
	{
		texture_y = (int)wall->tex_pos & (game->texture->height - 1);
		wall->tex_pos += wall->tex_step;
		color = get_texture_color(game->texture, wall->texture_x, texture_y);
		mlx_put_pixel(game->mlx_image, pixel, y, color);
		y++;
	}
}

void	draw_wall(t_dda *ray, t_cub *game, int pixel)
{
	t_wall	wall;

	game->texture = set_wall(game, ray);
	calculate_wall_params(ray, game, &wall);
	render_wall(game, pixel, &wall);
}
