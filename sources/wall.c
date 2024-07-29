#include "../includes/cub.h"

static int	is_open(char **map, int *line, int *column)
{
	if (map[*line][*column] != '1' && map[*line][*column] != ' ')
	{
		if (line == 0 && map[*line + 1] == '\n')
			return (1);
	}
	return (0);
}

int	surrounded_by_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (is_open(data->map, &i, &j) == 1)
			{
				printf("esta aberto.\n");
				return (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
