#include "../includes/cub.h"

void	get_max_lines(t_validate *data)
{
	int	lines;

	lines = 0;
	while (data->clone_map[lines])
		lines++;
	data->lines = lines;
}

void	get_max_columns(t_validate *data)
{
	int	max_columns;
	int	columns;
	int	i;

	max_columns = 0;
	i = 0;
	while (data->clone_map[i])
	{
		columns = ft_strlen(data->clone_map[i]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		i++;
	}
	data->columns = max_columns;
}

void	flood_fill(t_validate *data, int x, int y)
{
	if (x < 0 || x >= data->lines
		|| y < 0 || y >= data->columns
		|| data->clone_map[x][y] != '0')
		return ;

}


// void floodFill(char **map, int x, int y, int rows, int cols) {
//     // Verifica se a posição está fora dos limites ou se não é espaço vazio
//     if (x < 0 || x >= rows || y < 0 || y >= cols || map[x][y] != '0') {
//         return;
//     }

//     // Marca a posição atual como preenchida
//     map[x][y] = 'F';

//     // Preenche as posições adjacentes
//     floodFill(map, x+1, y, rows, cols);
//     floodFill(map, x-1, y, rows, cols);
//     floodFill(map, x, y+1, rows, cols);
//     floodFill(map, x, y-1, rows, cols);
// }

// int	check_borders(t_data *data)
// {
// 	size_t	x;
// 	size_t	y;
// 	size_t	max_lines;
// 	size_t	max_columns;

// 	max_lines = get_max_lines(data->map);
// 	max_columns = get_max_columns(data->map);
// 	y = 0;
// 	while (y < max_columns)
// 	{
// 		if (data->map[0][y] != '1')
// 			return (1);
// 		y++;
// 	}
// 	y = 0;
// 	while (y < max_columns)
// 	{
// 		if (max_lines > 0 && data->map[max_lines - 1][y] != '1')
// 			return (1);
// 		y++;
// 	}
// 	x = 0;
// 	while (x < max_lines)
// 	{
// 		if (data->map[x][0] != '1')
// 			return (1);
// 		if (ft_strlen(data->map[x]) > 0
// 			&& data->map[x][ft_strlen(data->map[x]) - 1] != '1')
// 			return (1);
// 		x++;
// 	}
// 	return (0);
// }


