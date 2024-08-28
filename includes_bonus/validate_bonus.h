/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:24:10 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/28 12:30:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_BONUS_H
# define VALIDATE_BONUS_H

# include "../libft/src/libft.h"
# include "structs_bonus.h"

# define WARNING_ARGS_1 "Error: no map file.\n"
# define WARNING_ARGS_2 "Error: too many arguments.\n"
# define WARNING_EXT "Error: the map file must be .cub\n"
# define WARNING_PLAYER "Error: invalid player.\n"
# define WARNING_INVALID "Error: there are invalid characters on the map.\n"
# define WARNING_EMPTY_LINE "Error: empty line.\n"
# define WARNING_OPEN_MAP "Error: map is open.\n"

/* VALIDATION */
void		validate_map(int argc, char **argv, t_cub *game);
void		check_arguments(int argc);
void		check_extension(char *map_file);
void		check_map_content(t_validate *valid);
void		check_rgb(uint32_t *color, char *rgb_color, char *original, char c);
void		split_rgb(char ***rgb, char *rgb_color, char *original, char c);
uint32_t	convert_rgb(int r, int g, int b);
int			check_path(char *path);

/* DATA PROCESSING */
void		data_processing(char *map_file, t_data *data);
void		read_textures_path(t_data *data, char *temp, int fd);

/* MAP */
void		count_map_size(t_data *data, char *temp, int fd);
void		read_and_copy_map_content(char *temp, int fd);
void		analyze_map_content(t_data *data, t_validate *valid);
void		get_max_columns(t_data *data);
void		get_max_lines(t_data *data);
int			check_invalid_char(char c);

/* WALL */
void		surrounded_by_walls(t_data *data);
bool		check_diagonals(t_data *data, int line, int col);
bool		check_sides(t_data *data, int line, int col);

/* TAB */
int			count_tabs(char *line);
void		found_tabs(t_data *data);
char		*replace_tabs(char *line, int tabs);

#endif
