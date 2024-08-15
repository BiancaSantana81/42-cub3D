#include "../../includes/cub.h"

static void	define_initial_plane(t_cub *game)
{
	if (game->data->pov_player == 'N')
	{
		game->dir = create_vector(0, -1);
		game->camera_plane = create_vector(0.66, 0);
	}
	else if (game->data->pov_player == 'S')
	{
		game->dir = create_vector(0, 1);
		game->camera_plane = create_vector(-0.66, 0);
	}
	else if (game->data->pov_player == 'W')
	{
		game->dir = create_vector(-1, 0);
		game->camera_plane = create_vector(0, -0.66);
	}
	else if (game->data->pov_player == 'E')
	{
		game->dir = create_vector(1, 0);
		game->camera_plane = create_vector(0, 0.66);
	}
}

void	setup(t_cub *game)
{
	game->pos = create_vector(game->data->x_player + 0.5,
			game->data->y_player + 0.5);
	define_initial_plane(game);
}

void	update_fps(t_cub *game)
{
	char				*fps_nbr;
	char				*fps_txt;
	static int			fps_len;
	static mlx_image_t	*fps_image;

	if (fps_len % 15 == 0)
	{
		game->frame_time = game->mlx->delta_time;
		if (fps_image)
			mlx_delete_image(game->mlx, fps_image);
		fps_nbr = ft_itoa(1 / game->mlx->delta_time);
		fps_txt = ft_strjoin("FPS: ", fps_nbr);
		free(fps_nbr);
		fps_image = mlx_put_string(game->mlx, fps_txt,
				WIDTH - 80, HEIGHT - 590);
		free(fps_txt);
	}
}
