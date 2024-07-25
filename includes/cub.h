#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "structs.h"
# include "validate.h"
# include "../libft/src/libft.h"

/* UTILS */
void	handle_error(char *error);
void	free_data(t_data *data);
t_data	*get_data(t_data *data);

/* INIT */
void	init_data(t_data *data);

#endif
