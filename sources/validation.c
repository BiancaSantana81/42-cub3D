#include "../includes/cub.h"

int	validate_map(int argc, char **argv)
{
	check_arguments(argc);
	(void)argv;
	if (!check_extension(argv[1]))
	{
		printf(WARNING_EXT);
		exit(EXIT_FAILURE);
	}
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

int	check_extension(char *map)
{
	char	*dotcub;
	int		i;
	int		len;

	i = 0;
	dotcub = ".cub";
	len = ft_strlen(map);
	len = len - 4;
	while (map[len] && dotcub[i] && map[len] == dotcub[i])
	{
		i++;
		len++;
	}
	if (dotcub[i] == '\0')
		return (1);
	else
		return (0);
}
