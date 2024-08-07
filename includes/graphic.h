#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"

/* HOOKS */
int32_t		key_pressed(mlx_key_data_t keydata, keys_t key);
void		hook_key_press(mlx_key_data_t keydata, void *param);
void		hook_close(void *param);
void		calculate_window_size(t_cub *game);

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

/* DRAW */
void		draw(t_cub *game);
void		draw_rays(t_cub *game);

/* VECTORS */
t_vector	create_vector(float x, float y);
t_vector	mult_vector(t_vector v, double scalar);
t_vector	add_vector(t_vector v1, t_vector v2);
float		mag_vector(t_vector v);



/* BRESENHAM */
void		bresenham_algorithm(mlx_image_t *image,
				int x0, int y0, int x1, int y1);

#endif
