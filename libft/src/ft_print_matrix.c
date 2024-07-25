
#include "libft.h"

void ft_print_matrix(char **matrix)
{
	int i;
	int	j;

	i = 0;
	while(matrix[i])
	{
		j = 0;
		while(matrix[i][j])
		{
			write(1, &matrix[i][j], 1);
			j++;
		}
		i++;
	}
}
