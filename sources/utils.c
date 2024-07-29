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

t_data	*get_data(t_data *data)
{
	static t_data	*data_ptr;

	if (data)
		data_ptr = data;
	return (data_ptr);
}

t_cub	*get_game(t_cub *game)
{
	static t_cub	*game_ptr;

	if (game)
		game_ptr = game;
	return (game_ptr);
}

void	free_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		ft_free_matrix(data->map);
	if (data)
		free(data);
}

void	free_memory(t_cub *game)
{
	if (game)
		free_data(game->data);
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
	if (action == INIT)
	{
		game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
		if (!game->mlx)
			puts(mlx_strerror(mlx_errno));
	}
	else if (action == NEW_IMAGE)
	{
		// add funções MLX necessárias;
		return ;
	}
	else if (action == IMAGE_TO_WIDOW)
	{
		// add funções MLX necessárias;
		return ;
	}
}
