#include "../includes/cub.h"

void	check_rgb(uint32_t *color, char *rgb_color)
{
	char		**rgb;
	int			i;
	int			j;

	i = 0;
	split_rgb(&rgb, rgb_color);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
			{
				ft_free_matrix(rgb);
				free(rgb_color);
				handle_error("Error: invalid rgb color\n");
			}
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
		{
			ft_free_matrix(rgb);
			free(rgb_color);
			handle_error("Error: invalid rgb color\n");
		}
		i++;
	}
	*color = convert_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_matrix(rgb);
}

void	split_rgb(char ***rgb, char *rgb_color)
{
	char	*temp_strim;
	int		i;

	i = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == 'F' || *rgb_color == 'C')
		rgb_color++;
	*rgb = ft_split(rgb_color, ',');
	if (!*rgb)
	{
		free(rgb_color);
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
	{
		ft_free_matrix(*rgb);
		free(rgb_color);
		handle_error("Error: invalid rgb color\n");
	}
}

uint32_t	convert_rgb(int r, int g, int b)
{
	return (((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b);
}
