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

bool	check_diagonals(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line > 0 && col > 0 && col < (int)ft_strlen(map[line - 1])
		&& (map[line - 1][col - 1] == ' ' || map[line - 1][col - 1] == '\n'))
		return (false);
	else if (line < data->lines - 1 && col > 0
		&& col < (int)ft_strlen(map[line + 1])
		&& (map[line + 1][col - 1] == ' ' || map[line + 1][col - 1] == '\n'))
		return (false);
	else if (line > 0 && col < (int)ft_strlen(map[line]) - 1
		&& col < (int)ft_strlen(map[line - 1])
		&& (map[line - 1][col + 1] == ' ' || map[line - 1][col + 1] == '\n'))
		return (false);
	else if (line < data->lines - 1 && col < (int)ft_strlen(map[line]) - 1
		&& col < (int)ft_strlen(map[line + 1])
		&& (map[line + 1][col + 1] == ' ' || map[line + 1][col + 1] == '\n'))
		return (false);
	return (true);
}

bool	check_sides(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (line > 0 && col < (int)ft_strlen(map[line - 1])
		&& (map[line - 1][col] == ' ' || map[line - 1][col] == '\n'))
		return (false);
	else if (line < data->lines - 1 && col < (int)ft_strlen(map[line + 1])
		&& (map[line + 1][col] == ' ' || map[line + 1][col] == '\n'))
		return (false);
	else if (col > 0
		&& (map[line][col - 1] == ' ' || map[line][col - 1] == '\n'))
		return (false);
	else if (col < (int)ft_strlen(map[line]) - 1
		&& (map[line][col + 1] == ' ' || map[line][col + 1] == '\n'))
		return (false);
	return (true);
}

void	surrounded_by_walls(t_data *data)
{
	char	**map;
	int		y;
	int		x;
	int		width;

	y = 0;
	map = data->map;
	while (map[y])
	{
		x = 0;
		width = ft_strlen(map[y]) - 1;
		while (x != width)
		{
			if (map[y][x] == '0' || ft_strchr("NSWE", map[y][x]))
			{
				if ((y == 0 || y == data->lines) || (x == 0 || x == width))
					handle_error("Error: invalid map, check de edges.\n");
				if (!check_sides(data, y, x) || !check_diagonals(data, y, x))
					handle_error("Error: invalid map, check the walls.\n");
			}
			x++;
		}
		y++;
	}
}
