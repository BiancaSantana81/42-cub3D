#include "../includes/cub.h"

static void	setup(t_cub *game);

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
	while (pixel < WIDHT)
	{
		mult = 2 *(pixel / (double)game->window_width) - 1;
		game->camera_pixel = mult_vector(game->camera_plane, mult);
		game->ray_dir = add_vector(game->dir, game->camera_pixel);
		game->delta_dist.x = mag_vector(game->ray_dir) / game->ray_dir.x;
		game->delta_dist.y = mag_vector(game->ray_dir) / game->ray_dir.y;
		//game->map pos precisa tirar as casas decimais de game->pos e arredondar, ou seja,
		//pos sera a posicao exata do jogador no mapa
		game->map_pos = create_vector(floor(game->pos.x), floor(game->pos.y));
		pixel++;
	}
}
