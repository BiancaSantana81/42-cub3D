#include "../includes/cub.h"

void	get_max_lines(t_data *data)
{
	int	lines;

	lines = 0;
	while (data->map[lines])
		lines++;
	data->lines = lines;
}

void	get_max_columns(t_data *data)
{
	int	max_columns;
	int	columns;
	int	i;

	max_columns = 0;
	i = 0;
	while (data->map[i])
	{
		columns = ft_strlen(data->map[i]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		i++;
	}
	data->columns = max_columns;
}
