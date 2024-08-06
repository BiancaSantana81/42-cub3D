#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, game.data);
	init_game(&game);
	return (EXIT_SUCCESS);
}

int	init_game(t_cub *game)
{
	handle_mlx_actions(INIT, game);
	handle_mlx_actions(NEW_IMAGE, game);
	draw_map(game);
<<<<<<< HEAD
	draw_player(game);
=======
	update_pa(game);
	draw_player_square(game);
>>>>>>> a8f3e5b4e1c8cfa523002c105d14ff6971e0ceff
	draw_player_direction(game);
	mlx_key_hook(game->mlx, &hook_key_press, game);
	mlx_close_hook(game->mlx, hook_close, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
