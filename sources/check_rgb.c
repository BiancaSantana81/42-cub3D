#include "../includes/cub.h"

uint32_t	check_rgb(char *rgb_color)
{
	char		**rgb;
	uint32_t	color;
	int			i;
	int			j;

	i = 0;
	rgb = split_rgb(rgb_color);
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
			{
				ft_free_matrix(rgb);
				handle_error("Error: invalid rgb color\n");
			}
			j++;
		}
		color = ft_atoi(rgb[i]);
		if (color < 0 || color > 255)
		{
			ft_free_matrix(rgb);
			handle_error("Error: invalid rgb color\n");
		}
		i++;
	}
	color = convert_rgb(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free_matrix(rgb);
	return (color);
}

char	**split_rgb(char *rgb_color)
{
	char	**rgb;
	int		i;

	i = 0;
	while (ft_isspace(*rgb_color) || *rgb_color == 'F' || *rgb_color == 'C')
		rgb_color++;
	rgb = ft_split(rgb_color, ',');
	while (rgb[i])
	{
		rgb[i] = ft_strtrim(rgb[i], " \t\v\f\r\n\b");
		i++;
	}
	rgb[i] = NULL;
	if (i != 3)
	{
		ft_free_matrix(rgb);
		handle_error("Error: invalid rgb color\n");
	}
	return (rgb);
}

uint32_t	convert_rgb(int r, int g, int b)
{
	return (((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b);
}
