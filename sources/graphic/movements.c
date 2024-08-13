#include "../../includes/cub.h"

void	handle_player_movement(t_cub *game,
	mlx_key_data_t keydata, float move_speed)
{
	if (key_pressed(keydata, MLX_KEY_W))
	{
		game->pos.x += game->dir.x * move_speed;
		game->pos.y += game->dir.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_S))
	{
		game->pos.x -= game->dir.x * move_speed;
		game->pos.y -= game->dir.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_A))
	{
		game->pos.x -= game->camera_plane.x * move_speed;
		game->pos.y -= game->camera_plane.y * move_speed;
	}
	else if (key_pressed(keydata, MLX_KEY_D))
	{
		game->pos.x += game->camera_plane.x * move_speed;
		game->pos.y += game->camera_plane.y * move_speed;
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
