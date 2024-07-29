#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	*game;

	game = NULL;
	init_cub(&game);
	validate_map(argc, argv, game->data);
	handle_mlx_actions(INIT, game);
	mlx_loop(game->mlx);
	free_memory(game);
	return (EXIT_SUCCESS);
}
