#include "../includes/cub.h"

static int	check_invalid_char(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0' && c != '1'
		&& c != '\0' && c != '\n' && (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	analyze_map_content(t_data *data, t_validate *valid)
{
	int			i;
	int			j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] == '\n')
			valid->n++;
		while (data->map[i][j])
		{
			if (check_invalid_char(data->map[i][j]) == 1)
				valid->invalid++;
			else if (data->map[i][j] == 'N'
				|| data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				valid->player++;
				valid->pos_player = data->map[i][j];
			}
			j++;
		}
		i++;
	}
}

int	check_map_content(t_validate *valid)
{
	if (valid->player != 1)
		return (handle_error(WARNING_PLAYER), (EXIT_FAILURE));
	else if (valid->invalid != 0)
		return (handle_error(WARNING_INVALID), (EXIT_FAILURE));
	else if (valid->n != 0)
		return (handle_error(WARNING_EMPTY_LINE), (EXIT_FAILURE));
	return (0);
}
