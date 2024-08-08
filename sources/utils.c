#include "../includes/cub.h"

void	handle_error(char *error)
{
	t_cub	*game;

	game = get_game(NULL);
	if (game->player)
		free(game->player);
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
	int		window_width;
	int		window_height;

	data = game->data;
	window_width = BLOCK * data->columns;
	window_height = BLOCK * data->lines;
	if (action == INIT)
	{
		game->mlx = mlx_init(window_width, window_height, "CUB3D", true);
		if (!game->mlx)
			puts(mlx_strerror(mlx_errno));
	}
	else if (action == NEW_IMAGE)
	{
		game->mlx_image = mlx_new_image(game->mlx, data->columns * BLOCK,
				data->lines * BLOCK);
		game->map_image = mlx_new_image(game->mlx, data->columns * BLOCK,
				data->lines * BLOCK);
		game->line_image = mlx_new_image(game->mlx, data->columns * BLOCK,
				data->lines * BLOCK);
		game->plane_line = mlx_new_image(game->mlx, data->columns * BLOCK,
				data->lines * BLOCK);
	}
	else if (action == IMAGE_TO_WINDOW)
	{
		//mlx_image_to_window(game->mlx, game->mlx_image, 0, 0);
	}
}

void	clear_line_image(t_cub *game, mlx_image_t *image)
{
	int	line;
	int	column;

	line = 0;
	while (line < (int)game->line_image->height)
	{
		column = 0;
		while (column < (int)game->line_image->width)
		{
			mlx_put_pixel(image, column, line, 0x00000000);
			column++;
		}
		line++;
	}
}
