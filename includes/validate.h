#ifndef VALIDATE_H
# define VALIDATE_H

# include "../libft/src/libft.h"
# include "structs.h"

# define WARNING_ARGS_1 "Error: No map file\n"
# define WARNING_ARGS_2 "Error: too many arguments\n"
# define WARNING_EXT "Error: the map file must be .cub\n"

int		validate_map(int argc, char **argv, t_data *data);
int		check_arguments(int argc);
int		check_extension(char *map_file);

int		data_processing(char *map_file, t_data *data);
void	read_textures_path(t_data *data, char *temp, int fd);
void	count_map_size(t_data *data, char *temp, int fd);
void	read_map_content(t_data *data, char *temp, int fd);

#endif
