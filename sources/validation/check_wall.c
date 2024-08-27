/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:26:43 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/27 12:28:52 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

bool	check_diagonal(t_data *data, int line, int column)
{
	
	
	return (true);
}

bool	check_sides(t_data *data, int line, int column)
{
	char	**map;

	map = data->map;
	if (map[line][column] == '0' || ft_strchr("NSWE", map[line][column]))
	{
		// if (line == 0 || line == data->lines - 1)
		// 	return (false);
		// else if (column == 0 || column == data->columns - 1)
		// 	return (false);
		else if (map[line - 1][column] == ' ' || (int)ft_strlen(map[line - 1]) - 1 < column)
			return (false);
		else if (map[line + 1][column] == ' ' || (int)ft_strlen(map[line + 1]) - 1 < column)
			return (false);
		else if (map[line][column - 1] == ' ' || map[line][column + 1] == ' ')
			return (false);
	}
	return (true);
}

int	surrounded_by_walls(t_data *data)
{
	char 	**map;
	int		line;
	int		column;
	int		width;

	line = 0;
	map = data->map;
	while (map[line])
	{
		column = 0;
		width = ft_strlen(map[line] -1);
		while (map[line][column] != width)
		{
			if (map[line][column] == '0'
				|| ft_strchr("NSWE", map[line][column]))
			{
				if ((line == 0 || line == data->lines) && (column == 0 || column == width))
					handle_error("Invalid map: check de edges");
				check_sides(data, line, column);
				check_diagonal(data, line, column);
			}
			column++;
		}
		line++;
	}
	return (EXIT_SUCCESS);
}
