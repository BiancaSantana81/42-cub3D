/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:20:16 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/29 13:20:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	check_colors(t_data *data, char *line, char *temp);

void	read_textures_path_aux(t_data *data, char *temp, char *line)
{
	if (ft_strncmp("NO", temp, 2) == 0)
		copy_texture_path(&(data->no), temp, "NO", line);
	else if (ft_strncmp("SO", temp, 2) == 0)
		copy_texture_path(&(data->so), temp, "SO", line);
	else if (ft_strncmp("WE", temp, 2) == 0)
		copy_texture_path(&(data->we), temp, "WE", line);
	else if (ft_strncmp("EA", temp, 2) == 0)
		copy_texture_path(&(data->ea), temp, "EA", line);
	else if (ft_strncmp("F", temp, 1) == 0)
		check_rgb(&data->floor, temp, line, 'F');
	else if (ft_strncmp("C", temp, 1) == 0)
		check_rgb(&data->ceiling, temp, line, 'C');
	else
	{
		if (temp[0] != '\n' && temp[0] != '\0')
		{
			free(line);
			handle_error("Error: invalid file.\n");
		}
	}
	check_colors(data, line, temp);
	data->size_textures++;
}

static void	check_colors(t_data *data, char *line, char *temp)
{
	static int	ceiling;
	static int	floor;

	if (ft_strncmp("F", temp, 1) == 0)
		floor++;
	if (ft_strncmp("C", temp, 1) == 0)
		ceiling++;
	if (ceiling == 1 && floor == 1)
		data->colors = true;
	if (ceiling > 1 || floor > 1)
	{
		free(line);
		handle_error("Error: duplicated color.\n");
	}
}

void	copy_texture_path(char **texture, char *path, char *mode,
	char *line)
{
	int		size_key;

	size_key = 0;
	if (*texture != NULL)
	{
		free(line);
		handle_error("Error: duplicated texture path.\n");
	}
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
		handle_error("Error: invalid texture path.\n");
	}
	*texture = ft_strdup(path);
}

void	trim_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || ft_isspace(str[i]))
		str[i] = '\0';
		i++;
	}
}
