#include "../includes/cub.h"

static void	setup(t_cub *game);

static void	define_dir_vector(t_cub *game)
{
	if (game->data->pov_player == 'N')
		game->dir = create_vector(-1, 0);
	else if (game->data->pov_player == 'S')
		game->dir = create_vector(1, 0);
	else if (game->data->pov_player == 'L')
		game->dir = create_vector(0, 1);
	else if (game->data->pov_player == 'E')
		game->dir = create_vector(0, -1);
	printf("dix_x: %f dir_y: %f", game->dir.x, game->dir.y);
}

void	draw(t_cub *game)
{
	draw_background(game);
	define_dir_vector(game);
	setup(game);
	draw_rays(game);
}

static void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player * (BLOCK / 2),
			game->data->y_player * (BLOCK / 2));
	//game->dir = create_vector(-1, 0);
	game->camera_plane = create_vector(0, 0.66);
}

void	draw_rays(t_cub *game)
{
	int		pixel;
	double	mult;

	pixel = 0;
	while (pixel < WIDHT)
	{
		mult = 2 *(pixel / (double)WIDHT) - 1;
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
