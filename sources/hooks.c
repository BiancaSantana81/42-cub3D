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

static int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	t_cub *game;
	(void)param;

	game = get_game(NULL);
	for (uint32_t i = 0; i < game->mlx_image->width; ++i)
	{
		for (uint32_t y = 0; y < game->mlx_image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(game->mlx_image, i, y, color);
		}
	}
}
