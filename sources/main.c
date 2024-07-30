#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, game.data);
	ft_print_matrix(game.data->map);
	//handle_mlx_actions(INIT, &game);
	//mlx_loop(game.mlx);
	free_memory(&game);
	return (EXIT_SUCCESS);
}
