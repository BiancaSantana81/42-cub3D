#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	validate_map(argc, argv, &data);
	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("F: %u\n", data.floor);
	printf("C: %u\n", data.ceiling);
	ft_print_matrix(data.map);
	free_data(&data);
	return (EXIT_SUCCESS);
}
