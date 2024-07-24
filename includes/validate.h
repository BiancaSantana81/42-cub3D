#ifndef VALIDATE_H
# define VALIDATE_H

# include "../libft/src/libft.h"
# define WARNING_ARGS_1 "Error: No map file"
# define WARNING_ARGS_2 "Error: too many arguments"
# define WARNING_EXT "Error: the map file must bem .cub"

int	validate_map(int argc, char **argv);
int	check_extension(char *map);
int	check_arguments(int argc);

#endif