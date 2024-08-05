#include "../includes/cub.h"

void	print_data(t_data data)
{
	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("F: %u\n", data.floor);
	printf("C: %u\n", data.ceiling);
	ft_print_matrix(data.map);
}


// Adcionar mlx_image_t line_image na struct e lines e columns na s_data

// void	draw_grid(t_cub *game)
// {
// 	int	line;
// 	int	line_pos;
// 	int	column;
// 	int	column_pos;
// 	int	width;
// 	int	height;

// 	width = game->data->window_width / game->data->columns;
// 	height = game->data->window_height / game->data->lines;
// 	line = 0;
// 	while (line < game->data->lines)
// 	{
// 		line_pos = line * width;
// 		draw_line(game->line_image, 0, line_pos, game->data->window_width, line_pos, 0xFF0000FF);
// 		line++;
// 	}
// 	column = 0;
// 	while (column < game->data->columns)
// 	{
// 		column_pos = column * height;
// 		draw_line(game->line_image, column_pos, 0, column_pos, game->data->window_height, 0xFF0000FF);
// 		column++;
// 	}
// }

// void draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1, uint32_t color)
// {
//     int dx = abs(x1 - x0);
//     int dy = abs(y1 - y0);
//     int sx = (x0 < x1) ? 1 : -1;
//     int sy = (y0 < y1) ? 1 : -1;
//     int err = dx - dy;

//     while (1)
//     {
//         if (x0 >= 0 && (uint32_t)x0 < image->width && y0 >= 0 && (uint32_t)y0 < image->height)
//             mlx_put_pixel(image, x0, y0, color);

//         if (x0 == x1 && y0 == y1)
//             break;
//         int e2 = err * 2;
//         if (e2 > -dy)
//         {
//             err -= dy;
//             x0 += sx;
//         }
//         if (e2 < dx)
//         {
//             err += dx;
//             y0 += sy;
//         }
//     }
// }

// void	calculate_window_size(t_cub *game)
// {
// 	game->data->window_width = BLOCK * game->data->columns;
// 	game->data->window_height = BLOCK * game->data->lines;
// }