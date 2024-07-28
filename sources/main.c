#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_cub	game;

	init_cub(&game);
	init_data(&data);
	validate_map(argc, argv, &data);
	handle_mlx_actions(INIT, &game);
	mlx_loop(game.mlx);
	free_data(&data);
	return (EXIT_SUCCESS);
}
