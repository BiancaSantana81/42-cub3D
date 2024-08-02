#include "../includes/cub.h"

void	handle_error(char *error)
{
	t_cub	*game;

	game = get_game(NULL);
	if (game)
		free_memory(game);
	ft_putstr_fd(error, 2);
	exit(1);
}

t_cub	*get_game(t_cub *game)
{
	static t_cub	*game_ptr;

	if (game)
		game_ptr = game;
	return (game_ptr);
}

int	open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		handle_error("Error: open file\n");
	return (fd);
}

void	handle_mlx_actions(int action, t_cub *game)
{
	t_data	*data;
	int		map_width;
	int		map_height;

	data = game->data;
	map_width = BLOCK * data->columns;
	map_height = BLOCK * data->lines;
	if (action == INIT)
	{
		game->mlx = mlx_init(map_width, map_height, "CUB3D", true);
		if (!game->mlx)
			puts(mlx_strerror(mlx_errno));
	}
	else if (action == NEW_IMAGE)
		game->mlx_image = mlx_new_image(game->mlx, 128, 128);
	else if (action == IMAGE_TO_WIDOW)
	{
		mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	}
}

void	calculate_window_size(t_cub *game)
{
	game->data->map_width = BLOCK * game->data->columns;
	game->data->map_height = BLOCK * game->data->lines;
}
