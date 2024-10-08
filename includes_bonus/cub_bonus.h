/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:23:41 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:23:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_BONUS_H
# define CUB_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "structs_bonus.h"
# include "validate_bonus.h"
# include "graphic_bonus.h"
# include "../libft/src/libft.h"

# define WIDTH 800
# define HEIGHT 600
# define MINI_WIDTH 200
# define MINI_HEIGHT 200
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
void	free_sprite(t_cub *game, t_images *sprite);

#endif
