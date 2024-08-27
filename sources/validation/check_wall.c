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
	if (map[line - 1][col - 1] == ' ' || map[line - 1][col - 1] == '\n')
	{
		printf("Error: empty line on upper left diagonal\n");
		return (false);
	}
	else if (map[line + 1][col - 1] == ' ' || map[line + 1][col - 1] == '\n')
	{
		printf("Error: empty line on bottom left diagonal\n");
		return (false);
	}
	else if (map[line - 1][col + 1] == ' ' || map[line - 1][col + 1] == '\n')
	{
		printf("Error: empty line on upper right diagonal\n");
		return (false);
	}
	else if (map[line + 1][col + 1] == ' ' || map[line + 1][col + 1] == '\n')
	{
		printf("Error: empty line on bottom right diagonal\n");
		return (false);
	}
	return (true);
}

bool	check_sides(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (map[line - 1][col] == ' ' || map[line - 1][col] == '\n')
	{
		handle_error("Error: empty line above\n");
		return (false);
	}
	else if (map[line + 1][col] == ' ' || map[line + 1][col] == '\n')
	{
		printf("Error: empty line below\n");
		return (false);
	}
	else if (map[line][col - 1] == ' ' || map[line][col - 1] == '\n')
	{
		printf("Error: empty line left side\n");
		return (false);
	}
	else if (map[line][col + 1] == ' ' || map[line][col + 1] == '\n')
	{
		printf("Error: empty line right side\n");
		return (false);
	}
	return (true);
}

int	surrounded_by_walls(t_data *data)
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
				if ((y == 0 || y == data->ys) || (x == 0 || x == width))
					handle_error("Invalid map: check de edges\n");
				if (!check_sides(data, y, x) || !check_diagonals(data, y, x))
					handle_error("Invalid map: check the walls\n");
			}
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}
