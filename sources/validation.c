#include "../includes/cub.h"

int	validate_map(int argc, char **argv, t_data *data)
{
	check_arguments(argc);
	check_extension(argv[1]);
	data_processing(argv[1], data);
	return (EXIT_SUCCESS);
}

int	check_arguments(int argc)
{
	if (argc < 2)
	{
		printf(WARNING_ARGS_1);
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		printf(WARNING_ARGS_2);
		exit(EXIT_FAILURE);
	}
	else
		return (EXIT_SUCCESS);
}

int	check_extension(char *map_file)
{
	char	*dotcub;
	int		i;
	int		len;

	i = 0;
	dotcub = ".cub";
	len = ft_strlen(map_file);
	len = len - 4;
	while (map_file[len] && dotcub[i] && map_file[len] == dotcub[i])
	{
		i++;
		len++;
	}
	if (dotcub[i] == '\0')
		return (EXIT_SUCCESS);
	printf(WARNING_EXT);
	exit(EXIT_FAILURE);
}
