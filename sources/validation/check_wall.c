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

static void fill_map_with_twos(t_data *data);

bool	check_diagonals(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (map[line - 1][col - 1] == ' ' || map[line - 1][col - 1] == '\n')
		return (false);
	else if (map[line + 1][col - 1] == ' ' || map[line + 1][col - 1] == '\n')
		return (false);
	else if (map[line - 1][col + 1] == ' ' || map[line - 1][col + 1] == '\n')
		return (false);
	else if (map[line + 1][col + 1] == ' ' || map[line + 1][col + 1] == '\n')
		return (false);
	return (true);
}

bool	check_sides(t_data *data, int line, int col)
{
	char	**map;

	map = data->map;
	if (map[line - 1][col] == ' ' || map[line - 1][col] == '\n')
		return (false);
	else if (map[line + 1][col] == ' ' || map[line + 1][col] == '\n')
		return (false);
	else if (map[line][col - 1] == ' ' || map[line][col - 1] == '\n')
		return (false);
	else if (map[line][col + 1] == ' ' || map[line][col + 1] == '\n')
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
	fill_map_with_twos(data);
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
	handle_error("Error: invalid map, check the walls.\n");
}

static void fill_map_with_twos(t_data *data)
{
	int		i;
	int		j;
	int		len;
	char	**new_map;
	
	i = 0;
	new_map = ft_calloc(data->lines + 1, sizeof(char *));
	while (i < data->lines)
	{
		new_map[i] = ft_calloc((data->columns + 2), sizeof(char));
		len = strlen(data->map[i]);
		ft_strncpy(new_map[i], data->map[i], len);
		j = len;
		printf("antes: %s\n", new_map[i]);
		while (j < data->columns)
		{
			new_map[i][j] = '2';
			j++;
		}
		printf("depois: %s\n", new_map[i]);
		new_map[i][j] = '\0';
		i++;
	}
	ft_free_matrix(data->map);
	data->map = new_map;
}
