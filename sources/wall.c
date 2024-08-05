#include "../includes/cub.h"

static int	is_open(t_data *data, int line, int column)
{
	char	**map;

	map = data->map;
	if (map[line][column] == '0' || ft_strchr("NSWE", map[line][column]))
	{
		if (line == 0 || line == data->lines)
			return (0);
		else if (column == 0 || column == data->columns - 1)
			return (0);
		else if (map[line - 1][column] == ' ' || map[line + 1][column] == ' ')
			return (0);
	}
	return (1);
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
			if (data->map[line][column] == '\0')
				break ;
			if (!is_open(data, line, column))
				return (handle_error(WARNING_OPEN_MAP), (EXIT_FAILURE));
			column++;
		}
		line++;
	}
	return (EXIT_SUCCESS);
}
