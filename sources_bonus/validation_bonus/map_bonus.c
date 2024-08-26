/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:56 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:30:58 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

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

void	read_and_copy_map_content(t_data *data, char *temp, int fd)
{
	int		i;
	int		size;
	bool	empty_line;

	i = 0;
	size = 0;
	empty_line = false;
	temp = get_next_line(fd);
	while (temp)
	{
		if (i == 0 && temp[0] == '\n')
			empty_line = true;
		else
			empty_line = false;
		if (size >= data->size_textures && empty_line == false)
		{
			data->map[i] = ft_strdup(temp);
			i++;
		}
		size++;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
}

static int	check_invalid_char(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '\0'
		|| c == '\n' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	analyze_map_content(t_data *data, t_validate *valid)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] == '\n')
			valid->n++;
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

int	check_map_content(t_validate *valid)
{
	if (valid->invalid != 0)
		return (handle_error(WARNING_INVALID), (EXIT_FAILURE));
	else if (valid->player != 1)
		return (handle_error(WARNING_PLAYER), (EXIT_FAILURE));
	else if (valid->n != 0)
		return (handle_error(WARNING_EMPTY_LINE), (EXIT_FAILURE));
	return (0);
}
