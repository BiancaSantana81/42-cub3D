/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:27:06 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/28 12:34:33 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	is_not_bar_n(bool *is_map, bool *map_ended, char *temp, int size);

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
	if (map_size == 0)
		handle_error("Error: missing map.\n");
	data->map = ft_calloc(sizeof(char *), (map_size + 1));
	if (!data->map)
		handle_error("Error: ft_calloc.\n");
}

void	read_and_copy_map_content(char *temp, int fd)
{
	int		size;
	bool	is_map;
	bool	map_ended;

	size = 0;
	is_map = false;
	map_ended = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (temp[0] == '\n')
		{
			if (is_map && !map_ended)
				map_ended = true;
		}
		else
			is_not_bar_n(&is_map, &map_ended, temp, size);
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

static void	is_not_bar_n(bool *is_map, bool *map_ended, char *temp, int size)
{
	t_cub		*game;
	static int	i;

	game = get_game(NULL);
	if (*map_ended)
	{
		free(temp);
		handle_error("Error: map invalid.\n");
	}
	if (size >= game->data->size_textures)
	{
		game->data->map[i] = ft_strdup(temp);
		i++;
		*is_map = true;
	}
}

void	analyze_map_content(t_data *data, t_validate *valid)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (check_invalid_char(data->map[i][j]) == 0)
				valid->invalid++;
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				valid->player++;
				data->pov_player = data->map[i][j];
				data->y_player = i;
				data->x_player = j;
			}
			j++;
		}
		i++;
	}
}
