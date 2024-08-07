#include "../includes/cub.h"

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
		game->mlx_image->instances[0].y -= 5;
		game->line_image->instances[0].y -=5;
	}
	else if (key_pressed(keydata, MLX_KEY_S))
	{
		game->mlx_image->instances[0].y += 5;
		game->line_image->instances[0].y += 5;
	}
	else if (key_pressed(keydata, MLX_KEY_A))
	{
		game->mlx_image->instances[0].x -= 5;
		game->line_image->instances[0].x -= 5;
	}
	else if (key_pressed(keydata, MLX_KEY_D))
	{
		game->mlx_image->instances[0].x += 5;
		game->line_image->instances[0].x += 5;
	}
	else if (key_pressed(keydata, MLX_KEY_LEFT))
		buttons(game, 'l');
	else if (key_pressed(keydata, MLX_KEY_RIGHT))
		buttons(game, 'r');
	game->player->x = game->mlx_image->instances[0].x;
	game->player->y = game->mlx_image->instances[0].y;
	printf("x: %d, y: %d\n", game->mlx_image->instances[0].x, game->mlx_image->instances[0].y);
	printf("angle: %f\n", game->player->pa);
	printf("x player: %d, y player: %d\n", game->player->x, game->player->y);
}


void	hook_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	free(game->player);
	free_memory(game);
	//free_sprite(game, game->player);
	mlx_close_window(game->mlx);
}
