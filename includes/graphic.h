#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"
# define MOVE_SPEED game->frame_time * 6
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/* HOOKS */
void			hook_key_press(mlx_key_data_t keydata, void *param);
void			hook_close(void *param);

/* MOVEMENTS */
void			process_input(t_cub *game);
bool			can_move_to(t_cub *game, float new_x, float new_y);
void			calculate_new_position(t_cub *game, float *new_x, float *new_y);

/* IMAGES */
mlx_texture_t	*init_images(char *path);
void			load_textures(t_cub *game);
uint32_t		get_texture_color(mlx_texture_t *texture, int y, int x);

/* DRAW SQUARES */
//void			draw_player(t_cub *game);
//void			draw_player_square(t_cub *game,
//					int start_x, int start_y, int size);
//void			draw_map(t_cub *game);
//void			draw_map_square(t_cub *game, int start_x, int start_y,
//					uint32_t color);
void			draw_background(t_cub *game);

/* SET_WALL */
void			set_wall(t_cub*game, mlx_texture_t **wall);

/* BRESENHAM */
void			bresenham_algorithm(t_cub *game, int x0, int y0, int x1, int y1);

/* SETUP */
void	setup(t_cub *game);
void	update_fps(t_cub *game);

/* ALGORITHM */
void	draw_rays(t_cub *game);
void	calculate_delta_distance(t_dda *ray);
void	calculate_distance_to_side(t_dda *ray, t_cub *game);
void	dda_algorithm(t_dda *ray, t_cub *game);

/* DRAW LOOP */
void	draw_playerview(void *param);
void	draw_wall(t_dda *ray, t_cub *game, int pixel);

#endif
