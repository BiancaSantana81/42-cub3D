#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
//# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "validate.h"
# include "../libft/src/libft.h"

/* UTILS */
int	    open_file(char *filename);
void	handle_error(char *error);
void	free_data(t_data *data);
t_data	*get_data(t_data *data);

/* INIT */
void	init_data(t_data *data);
void	init_variables_valid(t_validate *valid);

#endif
