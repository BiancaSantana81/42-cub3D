#include "../includes/cub.h"

uint32_t	check_rgb(char *rgb_color)
{
	char		**rgb;
	uint32_t	converted;
	int			color;
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
				handle_error("Error: invalid rgb color\n");
			j++;
		}
		color = ft_atoi(rgb[i]);
		if (color < 0 || color > 255)
			handle_error("Error: invalid rgb color\n");
		i++;
	}
	converted = transform_rgb(ft_atoi(rgb[0]),
			ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	while (i >= 0)
		free(rgb[i--]);
	free(rgb);
	return (converted);
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
	if (i != 3)
		handle_error("Error: invalid rgb color\n");
	return (rgb);
}

uint32_t	transform_rgb(int r, int g, int b)
{
	return (((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b);
}
