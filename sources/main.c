#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, &game);
	init_game(&game);
	return (EXIT_SUCCESS);
}

int	init_game(t_cub *game)
{
	handle_mlx_actions(INIT, game);
	handle_mlx_actions(NEW_IMAGE, game);
	setup(game);
	draw(game);
	handle_mlx_actions(IMAGE_TO_WINDOW, game);
	mlx_key_hook(game->mlx, &hook_key_press, game);
	mlx_close_hook(game->mlx, hook_close, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}


void	handle_mlx_actions(int action, t_cub *game)
{
	//int	height;
	//int	width;

	//height = game->data->lines * BLOCK;
	//width = game->data->columns * BLOCK;
	if (action == INIT)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
		if (!game->mlx)
			puts(mlx_strerror(mlx_errno));
	}
	else if (action == NEW_IMAGE)
	{
		game->mlx_image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		game->walls_image = mlx_new_image(game->mlx, WALL, HEIGHT);
	}
	else if (action == IMAGE_TO_WINDOW)
	{
		mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
		mlx_image_to_window(game->mlx, game->walls_image, 0, 0);
	}
}
