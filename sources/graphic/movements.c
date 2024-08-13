#include "../../includes/cub.h"

bool	can_move_to(t_cub *game, float new_x, float new_y)
{
	if (game->data->map[(int)new_y][(int)new_x] == '1')
		return (false);
	return (true);
}

void	calculate_new_position(mlx_key_data_t keydata,
		float *new_x, float *new_y)
{
	t_cub	*game;

	game = get_game(NULL);
	*new_x = game->pos.x;
	*new_y = game->pos.y;
	if (key_pressed(keydata, MLX_KEY_W))
	{
		*new_x = game->pos.x + game->dir.x * MOVE_SPEED;
		*new_y = game->pos.y + game->dir.y * MOVE_SPEED;
	}
	else if (key_pressed(keydata, MLX_KEY_S))
	{
		*new_x = game->pos.x - game->dir.x * MOVE_SPEED;
		*new_y = game->pos.y - game->dir.y * MOVE_SPEED;
	}
	else if (key_pressed(keydata, MLX_KEY_A))
	{
		*new_x = game->pos.x - game->camera_plane.x * MOVE_SPEED;
		*new_y = game->pos.y - game->camera_plane.y * MOVE_SPEED;
	}
	else if (key_pressed(keydata, MLX_KEY_D))
	{
		*new_x = game->pos.x + game->camera_plane.x * MOVE_SPEED;
		*new_y = game->pos.y + game->camera_plane.y * MOVE_SPEED;
	}
}

void	handle_player_movement(t_cub *game,
	mlx_key_data_t keydata)
{
	float	new_x;
	float	new_y;

	calculate_new_position(keydata, &new_x, &new_y);
	if (can_move_to(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}

void	handle_player_rotate(t_cub *game, mlx_key_data_t keydata)
{
	if (key_pressed(keydata, MLX_KEY_LEFT))
	{
		game->dir = rotate_vector(game->dir, 1);
		game->camera_plane = rotate_vector(game->camera_plane, 1);
	}
	if (key_pressed(keydata, MLX_KEY_RIGHT))
	{
		game->dir = rotate_vector(game->dir, 1);
		game->camera_plane = rotate_vector(game->camera_plane, 1);
	}
}
