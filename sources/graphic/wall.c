#include "../../includes/cub.h"

static void	calculate_wall_params(t_dda *ray, t_cub *game, t_wall *wall);
static void	render_wall(t_cub *game, int pixel, t_wall *wall);

void	draw_wall(t_dda *ray, t_cub *game, int pixel)
{
	t_wall	wall;

	game->texture = set_wall(game, ray);
	calculate_wall_params(ray, game, &wall);
	render_wall(game, pixel, &wall);
}

static void	calculate_wall_params(t_dda *ray, t_cub *game, t_wall *wall)
{
	int		wall_height;
	float	wall_hit_x;

	//calcula altura da parede
	wall_height = (HEIGHT / ray->perp_dist);
	wall->line_start_y = (HEIGHT / 2 - wall_height / 2);
	wall->line_end_y = (HEIGHT / 2 + wall_height / 2);
	//limita altura da parede
	if (wall->line_start_y < 0)
		wall->line_start_y = 0;
	if (wall->line_end_y >= HEIGHT)
		wall->line_end_y = HEIGHT - 1;
	// Calcular a posição de interseção da parede no mundo
	if (ray->hit_side == 0)
		wall_hit_x = game->pos.y + ray->perp_dist * ray->dir.y;
	else
		wall_hit_x = game->pos.x + ray->perp_dist * ray->dir.x;
	wall_hit_x -= floor(wall_hit_x);
	// Calcular a posição x na textura
	wall->texture_x = (int)(wall_hit_x * game->texture->width);
	// Ajustes para direções específicas
	if ((ray->hit_side == 0 && ray->dir.x > 0)
		|| (ray->hit_side == 1 && ray->dir.y < 0))
		wall->texture_x = game->texture->width - wall->texture_x - 1;
	// Calcular o passo da textura (quanto subir/descer na textura a cada pixel da parede)
	wall->tex_step = 1.0 * game->texture->height / wall_height;
	// Calcular a posição inicial na textura
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
		// Calcular a coordenada y na textura
		texture_y = (int)wall->tex_pos & (game->texture->height - 1);
		wall->tex_pos += wall->tex_step;
		color = get_texture_color(game->texture, wall->texture_x, texture_y);
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
