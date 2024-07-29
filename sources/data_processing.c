#include "../includes/cub.h"

static void	read_textures_path_aux(t_data *data, char *temp);

int	data_processing(char *map_file, t_data *data)
{
	char	*temp;
	int		fd;

	fd = open_file(map_file);
	temp = NULL;
	read_textures_path(data, temp, fd);
	count_map_size(data, temp, fd);
	fd = open_file(map_file);
	read_map_content(data, temp, fd);
	return (EXIT_SUCCESS);
}

void	read_textures_path(t_data *data, char *temp, int fd)
{
	char	*line;

	temp = get_next_line(fd);
	while (temp)

	{
		line = temp;
		while (*temp >= 9 && *temp <= 13)
			temp++;
		read_textures_path_aux(data, temp);
		free(line);
		if (data->no && data->so && data->we && data->ea && data->floor
			&& data->ceiling)
			break ;
		temp = get_next_line(fd);
	}
	if (!temp)
		handle_error("Error\n");
}

// realizar validações de RGB e caminho aqui antes de atribuir
//check_path da sempre invalid
static void	read_textures_path_aux(t_data *data, char *temp)
{
	if (ft_strncmp("NO", temp, 2) == 0)
		data->no = ft_strdup(temp + 2);
	else if (ft_strncmp("SO", temp, 2) == 0)
		data->so = ft_strdup(temp + 2);
	else if (ft_strncmp("WE", temp, 2) == 0)
		data->we = ft_strdup(temp + 2);
	else if (ft_strncmp("EA", temp, 2) == 0)
		data->ea = ft_strdup(temp + 2);
	else if (ft_strncmp("F", temp, 1) == 0)
		data->floor = check_rgb(temp);
	else if (ft_strncmp("C", temp, 1) == 0)
		data->ceiling = check_rgb(temp);
	data->size_textures++;
}

void	count_map_size(t_data *data, char *temp, int fd)
{
	int	map_size;

	map_size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map_size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	data->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!data->map)
		handle_error("Error\n");
}

void	read_map_content(t_data *data, char *temp, int fd)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		if (size > data->size_textures)
		{
			data->map[i] = ft_strdup(temp);
			i++;
		}
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	data->map[i] = NULL;
	close(fd);
}
