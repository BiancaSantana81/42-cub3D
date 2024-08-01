#include "../includes/cub.h"

static void	read_textures_path_aux(t_data *data, char *temp);
static void	copy_texture_path(char **texture, char *path);

int	data_processing(char *map_file, t_data *data)
{
	char	*temp;
	int		fd;

	temp = NULL;
	fd = open_file(map_file);
	read_textures_path(data, temp, fd);
	count_map_size(data, temp, fd);
	fd = open_file(map_file);
	read_and_copy_map_content(data, temp, fd);
	get_max_columns(data);
	get_max_lines(data);
	return (EXIT_SUCCESS);
}

void	read_textures_path(t_data *data, char *temp, int fd)
{
	char	*line;

	temp = get_next_line(fd);
	while (temp)
	{
		line = temp;
		while (ft_isspace(*temp))
			temp++;
		read_textures_path_aux(data, temp);
		free(line);
		if (data->no && data->so && data->we && data->ea && data->colors)
			break ;
		temp = get_next_line(fd);
	}
	if (!temp)
		handle_error("Error\n");
}

static void	read_textures_path_aux(t_data *data, char *temp)
{
	static int	colors;

	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(data->no), temp);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(data->so), temp);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(data->we), temp);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(data->ea), temp);
	else if (ft_strncmp("F", temp, 1) == 0)
	{
		check_rgb(&data->floor, temp);
		colors++;
	}
	else if (ft_strncmp("C", temp, 1) == 0)
	{
		check_rgb(&data->ceiling, temp);
		colors++;
	}
	if (colors == 2)
		data->colors = true;
	data->size_textures++;
}

static void	copy_texture_path(char **texture, char *path)
{
	if (*texture != NULL)
		free(*texture);
	while (ft_isspace(*path) || *path == 'N' || *path == 'O' || *path == 'S'
		|| *path == 'E' || *path == 'W')
		path++;
	*texture = ft_strdup(path);
}
