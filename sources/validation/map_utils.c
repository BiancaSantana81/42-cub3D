/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:26:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:27:00 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	get_max_lines(t_data *data)
{
	int	lines;

	lines = 0;
	while (data->map[lines])
		lines++;
	data->lines = lines;
}

void	get_max_columns(t_data *data)
{
	int	max_columns;
	int	columns;
	int	i;

	max_columns = 0;
	i = 0;
	while (data->map[i])
	{
		columns = ft_strlen(data->map[i]) - 1;
		if (columns > max_columns)
			max_columns = columns;
		i++;
	}
	data->columns = max_columns;
}

void	check_map_content(t_validate *valid)
{
	if (valid->invalid != 0)
		handle_error(WARNING_INVALID);
	else if (valid->player != 1)
		handle_error(WARNING_PLAYER);
}

int	check_invalid_char(char c)
{
	if (c == ' ' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
		|| c == '0' || c == '1' || c == '\0'
		|| c == '\n' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
