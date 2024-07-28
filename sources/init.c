#include "../includes/cub.h"

void	init_data(t_data *data)
{
	data->size_textures = 0;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor = 0;
	data->ceiling = 0;
	data->map = NULL;
}

void	init_variables_valid(t_validate *valid)
{
	valid->invalid = 0;
	valid->player = 0;
	valid->n = 0;
}

