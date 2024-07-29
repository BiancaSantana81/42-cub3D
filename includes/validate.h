#ifndef VALIDATE_H
# define VALIDATE_H

# include "../libft/src/libft.h"
# include "structs.h"

# define WARNING_ARGS_1 "Error: No map file\n"
# define WARNING_ARGS_2 "Error: too many arguments\n"
# define WARNING_EXT "Error: the map file must be .cub\n"
# define WARNING_PLAYER "Error: invalid player\n"
# define WARNING_INVALID "Error: there are invalid characters on the map\n"
# define WARNING_EMPTY_LINE "Error: map invalid\n"

/* VALIDATION */
int			validate_map(int argc, char **argv, t_data *data);
int			check_arguments(int argc);
int			check_extension(char *map_file);
char		*check_path(char *path);
void		check_rgb(uint32_t *color, char *rgb_color);
void		split_rgb(char ***rgb, char *rgb_color);
uint32_t	convert_rgb(int r, int g, int b);

/* DATA PROCESSING */
int			data_processing(char *map_file, t_data *data);
void		read_textures_path(t_data *data, char *temp, int fd);
void		count_map_size(t_data *data, char *temp, int fd);
void		read_and_copy_map_content(t_data *data, char *temp, int fd);

/* MAP */
void		analyze_map_content(t_data *data, t_validate *valid);
int			check_map_content(t_validate *valid);

/* WALL */
int			surrounded_by_walls(t_data *data);

#endif
