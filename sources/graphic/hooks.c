#include "../../includes/cub.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key)
{
	return (keydata.key == key && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT));
}

void	hook_key_press(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;
	float	move_speed;

	game = (t_cub *)param;
	move_speed = 0.1;
	if (key_pressed(keydata, MLX_KEY_ESCAPE))
	{
		hook_close(game);
		return ;
	}
	handle_player_movement(game, keydata, move_speed);
	handle_player_rotate(game, keydata);
}

void	hook_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free_memory(game);
	mlx_close_window(game->mlx);
}
