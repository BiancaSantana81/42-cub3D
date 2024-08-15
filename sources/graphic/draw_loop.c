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
	float		tex_step;
	float		tex_pos;
	int			texture_x;
	int			texture_y;
	uint32_t	color;
	float		wall_hit_x;

	wall_height = (HEIGHT / ray->perp_dist);
	line_start_y = (HEIGHT / 2 - wall_height / 2);
	line_end_y = (HEIGHT / 2 + wall_height / 2);
	if (line_start_y < 0)
		line_start_y = 0;
	if (line_end_y >= HEIGHT)
		line_end_y = HEIGHT - 1;
	game->texture = set_wall(game, ray);
	// Calcular a posição de interseção da parede no mundo
	if (ray->hit_side == 0)
		wall_hit_x = game->pos.y + ray->perp_dist * ray->dir.y;
	else
		wall_hit_x = game->pos.x + ray->perp_dist * ray->dir.x;
	wall_hit_x -= floor(wall_hit_x); // Ajuste para o intervalo de 0 a 1

	// Calcular a posição x na textura
	texture_x = (int)(wall_hit_x * game->texture->width);
	// Ajustes para direções específicas
	if ((ray->hit_side == 0 && ray->dir.x > 0)
		|| (ray->hit_side == 1 && ray->dir.y < 0))
		texture_x = game->texture->width - texture_x - 1;
	// Calcular o passo da textura (quanto subir/descer na textura a cada pixel da parede)
	tex_step = 1.0 * game->texture->height / wall_height;

	// Calcular a posição inicial na textura
	tex_pos = (line_start_y - HEIGHT / 2 + wall_height / 2) * tex_step;

	// Loop para desenhar cada pixel da parede
	y = line_start_y;
	while (y < line_end_y)
	{
		// Calcular a coordenada y na textura
		texture_y = (int)tex_pos & (game->texture->height - 1);
		tex_pos += tex_step;

		// Obter a cor do pixel da textura
		color = get_texture_color(game->texture, texture_x, texture_y);

		// Desenhar o pixel na tela
		mlx_put_pixel(game->mlx_image, pixel, y, color);
		y++;
	}
}