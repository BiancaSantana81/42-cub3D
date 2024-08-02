#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, game.data);
	//calculate_window_size(&game);
	init_game(&game);
	return (EXIT_SUCCESS);
}

int	init_game(t_cub *game)
{
	handle_mlx_actions(INIT, game);
	handle_mlx_actions(NEW_IMAGE, game);
	draw_example_pixel(game);
	draw_grid(game);
	handle_mlx_actions(IMAGE_TO_WIDOW, game);
	mlx_key_hook(game->mlx, &hook_key_press, game);
	mlx_close_hook(game->mlx, hook_close, &game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
