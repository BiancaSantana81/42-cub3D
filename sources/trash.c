#include "../includes/cub.h"

void	print_data(t_data data)
{
	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("F: %s\n", data.floor);
	printf("C: %s\n", data.ceiling);
	ft_print_matrix(data.map);
}
