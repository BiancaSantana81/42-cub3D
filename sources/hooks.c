#include "../includes/cub.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1
			|| keydata.key == key2) && keydata.action == MLX_PRESS);
}

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		free_and_close(game);
		return ;
	}
}

void	free_and_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	mlx_close_window(game->mlx);
}
