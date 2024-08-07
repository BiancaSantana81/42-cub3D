#include "../../includes/cub.h"

static void	handle_error_rgb(char *rgb_color, char **rgb);

void	check_rgb(uint32_t *color, char *rgb_color)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	split_rgb(&rgb, rgb_color);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				handle_error_rgb(rgb_color, rgb);
			j++;
		}
		if (ft_atoi(rgb[i]) < 0 || ft_atoi(rgb[i]) > 255)
			handle_error_rgb(rgb_color, rgb);
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
		handle_error_rgb(rgb_color, *rgb);
}

uint32_t	convert_rgb(int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | 255);
}

static void	handle_error_rgb(char *rgb_color, char **rgb)
{
	free(rgb_color);
	ft_free_matrix(rgb);
	handle_error("Error: invalid rgb color\n");
}
