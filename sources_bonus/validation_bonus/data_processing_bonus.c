/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:47 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/28 12:20:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	data_processing(char *map_file, t_data *data)
{
	char	*temp;
	int		fd;

	temp = NULL;
	fd = open_file(map_file);
	read_textures_path(data, temp, fd);
	count_map_size(data, temp, fd);
	fd = open_file(map_file);
	read_and_copy_map_content(temp, fd);
	if (data->map == NULL)
		handle_error("Error: invalid map\n");
	get_max_columns(data);
	get_max_lines(data);
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
