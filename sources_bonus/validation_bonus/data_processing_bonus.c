/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:47 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/23 14:15:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	read_textures_path_aux(t_data *data, char *temp, char *line);
static void	copy_texture_path(char **texture, char *path, char *mode,
				char *line);
static void	trim_newline(char *str);

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
		read_textures_path_aux(data, temp, line);
		free(line);
		if (data->no && data->so && data->we && data->ea && data->colors)
			break ;
		temp = get_next_line(fd);
	}
	if (!temp)
		handle_error("Error: invalid texture\n");
}

static void	read_textures_path_aux(t_data *data, char *temp, char *line)
{
	static int	ceiling;
	static int	floor;

	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(data->no), temp, "NO", line);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(data->so), temp, "SO", line);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(data->we), temp, "WE", line);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(data->ea), temp, "EA", line);
	else if (ft_strncmp("F", temp, 1) == 0)
	{
		check_rgb(&data->floor, temp, line);
		floor++;
	}
	else if (ft_strncmp("C", temp, 1) == 0)
	{
		check_rgb(&data->ceiling, temp, line);
		ceiling++;
	}
	if (ceiling >= 1 && floor >= 1)
		data->colors = true;
	data->size_textures++;
}

static void	copy_texture_path(char **texture, char *path, char *mode,
	char *line)
{
	int		size_key;

	size_key = 0;
	while (ft_isspace(*path) || ft_strncmp(mode, path, 2) == 0)
	{
		if (ft_strncmp(mode, path, 2) == 0)
		{
			size_key++;
			path++;
		}
		path++;
	}
	trim_newline(path);
	if (!check_path(path) || size_key != 1)
	{
		free(line);
		handle_error("Error: invalid texture path\n");
	}
	if (*texture != NULL)
		free(*texture);
	*texture = ft_strdup(path);
}

static void	trim_newline(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '\n')
			str[len] = '\0';
		len++;
	}
}
