#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"
# define MOVE_SPEED 0.1
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

/* HOOKS */
int32_t		key_pressed(mlx_key_data_t keydata, keys_t key);
void		hook_key_press(mlx_key_data_t keydata, void *param);
void		hook_close(void *param);

/* MOVEMENTS */
bool		can_move_to(t_cub *game, float new_x, float new_y);
void		calculate_new_position(mlx_key_data_t keydata,
				float *new_x, float *new_y);
void		handle_player_movement(t_cub *game,
				mlx_key_data_t keydata);
void		handle_player_rotate(t_cub *game, mlx_key_data_t keydata);
void		rotate_player(void);

/* IMAGES */
t_images	*init_images(t_cub *game, char *path);
void		free_sprite(t_cub *game, t_images *image);
void		load_textures(t_cub *game);
void		draw_images(t_cub *game);

/* DRAW SQUARES */
void		draw_player(t_cub *game);
void		draw_player_square(t_cub *game, int start_x, int start_y, int size);
void		draw_map(t_cub *game);
void		draw_map_square(t_cub *game, int start_x, int start_y,
				uint32_t color);
void		draw_background(t_cub *game);

/* SET_WALLS */
void		set_wall(t_dda *ray, t_cub*game);

/* BRESENHAM */
void	bresenham_algorithm(t_cub *game, int x0, int y0, int x1, int y1);

#endif
