/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:23:52 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:23:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_BONUS_H
# define GRAPHIC_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/* HOOKS */
void			hook_key_press(mlx_key_data_t keydata, void *param);
void			hook_close(void *param);

/* MOVEMENTS */
void			process_input(t_cub *game, int32_t x);
bool			can_move_to(t_cub *game, float new_x, float new_y);
void			calculate_new_position(t_cub *game, float *new_x, float *new_y);

/* IMAGES */
mlx_texture_t	*init_textures(char *path);
void			load_textures(t_cub *game);
t_images		*init_generic_images(t_cub *game, char *path);
uint32_t		get_texture_color(mlx_texture_t *texture, int y, int x);
void			update_player(t_cub *game);

/* DRAW SQUARES */
void			draw_background(t_cub *game);

/* WALL */
mlx_texture_t	*set_wall(t_cub *game, t_dda *ray);
void			draw_wall(t_dda *ray, t_cub *game, int pixel);

/* SETUP */
void			setup(t_cub *game);
void			update_fps(t_cub *game);

/* ALGORITHM */
void			draw_rays(t_cub *game);
void			calculate_delta_distance(t_dda *ray);
void			calculate_distance_to_side(t_dda *ray, t_cub *game);
void			dda_algorithm(t_dda *ray, t_cub *game);

/* DRAW LOOP */
void			draw_playerview(void *param);

/* MINIMAP */
void			update_minimap(t_cub *game);
void			draw_minimap(void *param);
void			draw_map(t_cub *game, int scale);
void			draw_map_square(t_cub *game, t_square_params params);

/* MINIMAP PLAYER */
void			draw_player(t_cub *game, int scale);
void			draw_player_square(t_cub *game,
					int start_x, int start_y, int size);

#endif
