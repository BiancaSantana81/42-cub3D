#include "../includes/cub.h"

static void	setup(t_cub *game);
static void	calculate_dist_to_side(t_cub *game);

//loop principal para desenhar o jogo
void	draw(t_cub *game)
{
	draw_background(game);
	setup(game);
	draw_rays(game);
}

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
}

//inicializar a posição do player e a direção inicial
static void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player * (BLOCK / 2),
			game->data->y_player * (BLOCK / 2));
	//criar função para decidir a dir inicial do player for do loop principal
	game->dir = create_vector(0, -1);
	game->camera_plane = create_vector(0.66, 0);
}


static void	calculate_dist_to_side(t_cub *game)
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
		game->delta_dist.x = fabsf(mag_vector(game->ray_dir) / game->ray_dir.x);
		game->delta_dist.y = fabsf(mag_vector(game->ray_dir) / game->ray_dir.y);
		game->map_pos = create_vector(floor(game->pos.x), floor(game->pos.y));
		calculate_dist_to_side(game);
		game->hit = false;
		game->wall_map_pos = copy_vector(game->map_pos);
		pixel++;
	}
}

// se hitside = 0, bateu na parede na vertical
// se hitside = 1, bateu na parede na horizontal
static void	dda_algorithm(t_cub *game)
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
		if (game->data->map[(int)game->wall_map_pos.y]
			[(int)game->wall_map_pos.x] == '1')
			game->hit = true;
	}
}
