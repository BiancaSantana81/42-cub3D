#include "../includes/cub.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1 || keydata.key == key2)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT));
}

void	hook_key_press(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		hook_close(game);
		return ;
	}
	else if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		game->mlx_image->instances[0].y -= 5;
	else if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		game->mlx_image->instances[0].y += 5;
	else if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		game->mlx_image->instances[0].x -= 5;
	else if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		game->mlx_image->instances[0].x += 5;
}

void	hook_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free_memory(game);
	//free_sprite(game, game->player);
	mlx_close_window(game->mlx);
}