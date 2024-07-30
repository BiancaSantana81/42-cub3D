#include "../includes/cub.h"

static int	is_open(t_data *data, int line, int column)
{
	char	**map;

	map = data->map;
	if (map[line][column] == '0')
	{
		if (line == 0 || line == data->lines)
			return (1);
		else if (column == 0 || column == data->columns)
			return (1);
		else if (map[line - 1][column] == ' ' || map[line + 1][column] == ' ')
			return (1);
	}
	return (0);
}

int	surrounded_by_walls(t_data *data)
{
	int	line;
	int	column;

	line = 0;
	while (data->map[line])
	{
		column = 0;
		while (data->map[line][column] != '\n')
		{
			if (is_open(data, line, column) == 1)
				return (handle_error(WARNING_OPEN_MAP), (EXIT_FAILURE));
			column++;
		}
		line++;
	}
	return (EXIT_SUCCESS);
}
