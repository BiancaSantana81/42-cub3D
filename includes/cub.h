#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
//# include "../MLX42/include/MLX42/MLX42_Int.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "validate.h"
# include "graphic.h"
# include "../libft/src/libft.h"

# define BLOCK 32
# define PI 3.141592653589793
# define PI_90 1.5707963267948966  // π/2
# define PI_270 4.71238898038469   // 3π/2
# define PI_360 6.283185307179586  // 2π

/* UTILS */
int		open_file(char *filename);
void	handle_error(char *error);
void	free_data(t_data *data);
void	free_memory(t_cub *game);
t_cub	*get_game(t_cub *game);
void	handle_mlx_actions(int action, t_cub *game);

/* INIT */
void	init_cub(t_cub *game);
void	init_data(t_cub *game);
void	init_player(t_cub *game);
void	init_variables_valid(t_validate *valid);
int		init_game(t_cub *game);

/* TRASH */
void	print_data(t_data data);
void	generate_random_coordinates(int width, int height, int *x, int *y);

#endif
