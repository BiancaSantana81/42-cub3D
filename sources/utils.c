#include "../includes/cub.h"

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: open file\n");
	return (fd);
}

t_cub	*get_game(t_cub *game)
{
	static t_cub	*game_ptr;

	if (game)
		game_ptr = game;
	return (game_ptr);
}

void	handle_error(char *error)
{
	t_cub	*game;

	game = get_game(NULL);
	if (game)
		free_memory(game);
	ft_putstr_fd(error, 2);
	exit(1);
}

void	handle_mlx_error(char *error)
{
	t_cub	*game;

	game = get_game(NULL);
	if (game)
		free_memory(game);
	mlx_close_window(game->mlx);
	ft_putstr_fd(error, 2);
	exit(1);
}
