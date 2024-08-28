/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:30:29 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/28 12:35:02 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

static void	handle_error_rgb(char *rgb_color, char **rgb);
static void	control_characters(char *rgb_color, char *original, char c);

void	check_rgb(uint32_t *color, char *rgb_color, char *original, char c)
{
	char	**rgb;
	int		qtd;
	int		i;
	int		j;

	i = 0;
	qtd = 0;
	control_characters(rgb_color, original, c);
	split_rgb(&rgb, rgb_color, original, c);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				handle_error_rgb(original, rgb);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			handle_error_rgb(original, rgb);
		i++;
	}
	*color = convert_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_matrix(rgb);
}

static void	control_characters(char *rgb_color, char *original, char c)
{
	int	qtd;

	qtd = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
	{
		if (*rgb_color == c)
			qtd++;
		rgb_color++;
	}
	if (qtd != 1)
	{
		free(original);
		handle_error("Error: invalid rgb color\n");
	}
}

void	split_rgb(char ***rgb, char *rgb_color, char *original, char c)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == c)
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
	{
		free(original);
		handle_error("Error: invalid rgb color\n");
	}
	while ((*rgb)[i])
	{
		temp_strim = ft_strtrim((*rgb)[i], " \t\v\f\r\n\b");
		free((*rgb)[i]);
		(*rgb)[i] = temp_strim;
		i++;
	}
	if (i != 3)
		handle_error_rgb(original, *rgb);
}

uint32_t	convert_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	handle_error_rgb(char *original, char **rgb)
{
	free(original);
	ft_free_matrix(rgb);
	handle_error("Error: invalid rgb color\n");
}
