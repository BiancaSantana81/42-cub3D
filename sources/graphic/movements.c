#include "../../includes/cub.h"

bool	can_move_to(t_cub *game, float new_x, float new_y)
{
	if (game->data->map[(int)new_y][(int)new_x] == '1')
		return (false);
	return (true);
}

void	calculate_new_position(mlx_key_data_t keydata,
								float move_speed, float *new_x, float *new_y)
{
	t_cub	*game;

	game = get_game(NULL);
	if (key_pressed(keydata, MLX_KEY_W))
	{
		*new_x = game->pos.x + game->dir.x * move_speed;
		*new_y = game->pos.y + game->dir.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_S))
	{
		*new_x = game->pos.x - game->dir.x * move_speed;
		*new_y = game->pos.y - game->dir.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_A))
	{
		*new_x = game->pos.x - game->camera_plane.x * move_speed;
		*new_y = game->pos.y - game->camera_plane.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_D))
	{
		*new_x = game->pos.x + game->camera_plane.x * move_speed;
		*new_y = game->pos.y + game->camera_plane.y * move_speed;
	}
}

void	handle_player_movement(t_cub *game,
	mlx_key_data_t keydata, float move_speed)
{
	float	new_x;
	float	new_y;

	calculate_new_position(keydata, move_speed, &new_x, &new_y);
	if (can_move_to(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
}

void	handle_player_rotate(mlx_key_data_t keydata)
{
	if (key_pressed(keydata, MLX_KEY_LEFT))
	{
		// Rotacionar para a esquerda
	}
	else if (key_pressed(keydata, MLX_KEY_RIGHT))
	{
		// Rotacionar para a direita
	}
}

void	rotate_player(void)
{
	// rotacionar player;
    return ;
}
