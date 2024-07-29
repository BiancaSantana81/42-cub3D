#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	*game;

	game = NULL;
	init_cub(&game);
	validate_map(argc, argv, game->data);
	printf("floor: %u\n", game->data->floor);
	printf("ceiling: %u\n", game->data->ceiling);
	//handle_mlx_actions(INIT, game);
	//mlx_loop(game->mlx);
	free_memory(game);
	return (EXIT_SUCCESS);
}
