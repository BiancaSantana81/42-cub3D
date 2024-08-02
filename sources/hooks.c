#include "../includes/cub.h"

int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2)
{
	return ((keydata.key == key1
			|| keydata.key == key2) && keydata.action == MLX_PRESS);
}

void	ft_hooks(mlx_key_data_t keydata, void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	if (key_pressed(keydata, MLX_KEY_ESCAPE, MLX_KEY_ESCAPE))
	{
		free_and_close(game);
		return ;
	}
	else if (key_pressed(keydata, MLX_KEY_W, MLX_KEY_UP))
		game->mlx_image->instances[0].y -= 5;
	else if (key_pressed(keydata, MLX_KEY_S, MLX_KEY_DOWN))
		game->mlx_image->instances[0].y += 5;
	else if (key_pressed(keydata, MLX_KEY_A, MLX_KEY_LEFT))
		game->mlx_image->instances[0].x -= 5;
	else if (key_pressed(keydata, MLX_KEY_D, MLX_KEY_RIGHT))
		game->mlx_image->instances[0].x += 5;
}

void	free_and_close(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	mlx_close_window(game->mlx);
}

void	draw_example_pixel(t_cub *game)
{
	uint32_t	x;
	uint32_t	y;
	uint32_t	color;

	x = 5;
	y = 5;
	color = 0xFF0000FF;
	if (game->mlx_image)
		mlx_put_pixel(game->mlx_image, x, y, color);
}

void	draw_grid(t_cub *game)
{
	int	line;
	int	line_pos;
	int	column;
	int	column_pos;
	int	width;
	int	height;

	width = game->data->map_width / game->data->columns;
	height = game->data->map_height / game->data->lines;
	line = 0;
	while (line <= game->data->lines)
	{
		line_pos = line * width;
		draw_line(game->mlx_image, 0, line_pos, game->data->map_width, line_pos, 0xFF0000FF);
		line++;
	}
	while (column <= game->data->columns)
	{
		column_pos = column * height;
		draw_line(game->mlx_image, column_pos, 0, column_pos, game->data->map_height, 0xFF0000FF);
		column++;
	}
}

void draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_put_pixel(image, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = err * 2;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
