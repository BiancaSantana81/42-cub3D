#include "../includes/cub.h"

int	data_processing(char *map_file, t_data *data)
{
	char	*temp;
	int		fd;

	fd = open(map_file, O_RDONLY);
	temp = NULL;
	read_textures_path(data, temp, fd);
	//read_map(&data, fd);
	close(fd);
	return (EXIT_SUCCESS);
	//validar o mapa
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
		if (ft_strncmp("NO ", temp, 3) == 0)
			data->no = ft_strdup(temp + 3);
		else if (ft_strncmp("SO ", temp, 3) == 0)
			data->so = ft_strdup(temp + 3);
		else if (ft_strncmp("WE ", temp, 3) == 0)
			data->we = ft_strdup(temp + 3);
		else if (ft_strncmp("EA ", temp, 3) == 0)
			data->ea = ft_strdup(temp + 3);
		else if (ft_strncmp("F ", temp, 2) == 0)
			data->floor = ft_strdup(temp + 2);
		else if (ft_strncmp("C ", temp, 2) == 0)
			data->ceiling = ft_strdup(temp + 2);
		free(line);
		if (data->no && data->so && data->we && data->ea && data->floor
			&& data->ceiling)
			break ;
		temp = get_next_line(fd);
	}
	if (!temp)
		handle_error("Error\n");
}
