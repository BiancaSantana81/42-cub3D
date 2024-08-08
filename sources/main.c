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
		game->mlx = mlx_init(WIDHT, HEIGTH, "CUB3D", true);
		if (!game->mlx)
			puts(mlx_strerror(mlx_errno));
	}
	else if (action == NEW_IMAGE)
	{
		game->mlx_image = mlx_new_image(game->mlx, WIDHT, HEIGTH);
	}
	else if (action == IMAGE_TO_WINDOW)
	{
		mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	}
}
