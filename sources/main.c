#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, game.data);
	handle_mlx_actions(INIT, &game);
	mlx_key_hook(game.mlx, &ft_hooks, &game);
	mlx_close_hook(game.mlx, free_and_close, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_memory(&game);
	return (EXIT_SUCCESS);
}
