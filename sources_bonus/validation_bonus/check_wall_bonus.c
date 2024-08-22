/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:37 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:30:41 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static int	is_open(t_data *data, int line, int column)
{
	char	**map;

	map = data->map;
	if (map[line][column] == '0' || ft_strchr("NSWE", map[line][column]))
	{
		if (line == 0 || line == data->lines - 1)
			return (0);
		else if (column == 0 || column == data->columns - 1)
			return (0);
		else if (map[line - 1][column] == ' ' || map[line - 1][column] == '\n'
			|| (int)ft_strlen(map[line - 1]) - 1 < column)
			return (0);
		else if (map[line + 1][column] == ' ' || map[line + 1][column] == '\n'
			|| (int)ft_strlen(map[line + 1]) - 1 < column)
			return (0);
		else if (map[line][column - 1] == ' ' || map[line][column + 1] == ' '
			|| map[line][column + 1] == '\n')
			return (0);
	}
	return (1);
}

int	surrounded_by_walls(t_data *data)
{
	int	line;
	int	column;

	line = 0;
	while (data->map[line])
	{
		column = 0;
		while (data->map[line][column] != '\n')
		{
			if (data->map[line][column] == '\0')
				break ;
			if (is_open(data, line, column) == 0)
				return (handle_error(WARNING_OPEN_MAP), (EXIT_FAILURE));
			column++;
		}
		line++;
	}
	return (EXIT_SUCCESS);
}
