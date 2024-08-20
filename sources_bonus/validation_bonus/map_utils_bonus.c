/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:31:03 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:31:06 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

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

int	count_tabs(char *line)
{
	int	i;
	int	tabs;

	i = 0;
	tabs = 0;
	while (line[i])
	{
		if (line[i] == '\t')
			tabs++;
		i++;
	}
	return (tabs);
}

void	found_tabs(t_data *data)
{
	int		i;
	int		tabs;
	char	*to_free;

	i = 0;
	while (data->map[i])
	{
		tabs = count_tabs(data->map[i]);
		if (tabs > 0)
		{
			to_free = data->map[i];
			data->map[i] = replace_tabs(data->map[i], tabs);
			free(to_free);
		}
		i++;
	}
}

char	*replace_tabs(char *line, int tabs)
{
	char	*replaced;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	replaced = ft_calloc(sizeof(char), ft_strlen(line) + (tabs * 4) + 1);
	while (line[i])
	{
		x = 0;
		if (line[i] == '\t')
		{
			while (x++ < 4)
				replaced[j++] = ' ';
			i++;
			continue ;
		}
		replaced[j++] = line[i++];
	}
	return (replaced);
}
