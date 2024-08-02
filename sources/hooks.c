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
	else if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		game->mlx_image->instances[0].y -= 5;
	else if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		game->mlx_image->instances[0].y += 5;
	else if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		game->mlx_image->instances[0].x -= 5;
	else if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		game->mlx_image->instances[0].x += 5;
}

void	free_and_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	mlx_close_window(game->mlx);
}

void	draw_example_pixel(t_cub *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	x = 5;
	y = 5;
	color = 0xFF0000FF;
	if (game->mlx_image)
		mlx_put_pixel(game->mlx_image, x, y, color);
}
