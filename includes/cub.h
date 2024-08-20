/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:22:41 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:22:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs.h"
# include "validate.h"
# include "graphic.h"
# include "../libft/src/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define ROTATE_LEFT -0.5
# define ROTATE_RIGHT 0.5

/* MAIN */
int		init_game(t_cub *game);
void	handle_mlx_actions(int action, t_cub *game);

/* INIT */
void	init_cub(t_cub *game);
void	init_data(t_cub *game);
void	init_variables_valid(t_validate *valid);

/* UTILS */
int		open_file(char *filename);
t_cub	*get_game(t_cub *game);
void	handle_error(char *error);

/* FREE_MEMORY */
void	free_data(t_data *data);
void	free_memory(t_cub *game);

#endif
