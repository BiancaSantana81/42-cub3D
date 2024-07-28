#ifndef VALIDATE_H
# define VALIDATE_H

# include "../libft/src/libft.h"
# include "structs.h"

# define WARNING_ARGS_1 "Error: No map file\n"
# define WARNING_ARGS_2 "Error: too many arguments\n"
# define WARNING_EXT "Error: the map file must be .cub\n"
# define WARNING_PLAYER "Error: there are more than one player\n"
# define WARNING_INVALID "Error: there are invalid characters on the map\n"
# define WARNING_EMPTY_LINE "Error: map invalid\n"

/* VALIDATION */
int			validate_map(int argc, char **argv, t_data *data);
int			check_arguments(int argc);
int			check_extension(char *map_file);
char		*check_path(char *path);
uint32_t	check_rgb(char *rgb_color);
char		**split_rgb(char *rgb_color);
uint32_t	transform_rgb(int r, int g, int b);

/* DATA PROCESSING */
int			data_processing(char *map_file, t_data *data);
void		read_textures_path(t_data *data, char *temp, int fd);
void		count_map_size(t_data *data, char *temp, int fd);
void		read_map_content(t_data *data, char *temp, int fd);

/* MAP */
void		analyze_map_content(t_data *data, t_validate *valid);
int			check_map_content(t_validate *valid);

/* BORDERS */
void		get_max_lines(char **map);
void		get_max_columns(char **map);
int			check_borders(t_data *data);

#endif
