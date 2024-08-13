#include "../../includes/cub.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key)
{
	return (keydata.key == key && (keydata.action == MLX_PRESS
			|| keydata.action == MLX_REPEAT));
}

void	hook_key_press(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE))
	{
		hook_close(game);
		return ;
	}
	else if (key_pressed(keydata, MLX_KEY_W))
	{
		//game->mlx_image->instances[0].y -= 5;
		//game->line_image->instances[0].y -=5;
	}
	else if (key_pressed(keydata, MLX_KEY_S))
	{
		//game->mlx_image->instances[0].y += 5;
		//game->line_image->instances[0].y += 5;
	}
	else if (key_pressed(keydata, MLX_KEY_A))
	{
		//game->mlx_image->instances[0].x -= 5;
		//game->line_image->instances[0].x -= 5;
	}
	else if (key_pressed(keydata, MLX_KEY_D))
	{
		//game->mlx_image->instances[0].x += 5;
		//game->line_image->instances[0].x += 5;
	}
	else if (key_pressed(keydata, MLX_KEY_LEFT))
	{
	}
	else if (key_pressed(keydata, MLX_KEY_RIGHT))
	{

	}
}


void	hook_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free_memory(game);
	mlx_close_window(game->mlx);
}
