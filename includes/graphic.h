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

/* DRAW LINE */
void		update_pa(t_cub *game);
void		draw_line(t_cub *game, int lenght);
void		aux_draw_line(mlx_image_t *image, t_line *draw);
void		draw_player_direction(t_cub *game);


/* POSITION */
void		assing_position(t_cub *game, int start_x, int start_y);

/* BUTTONS */
void		buttons(t_cub *game, unsigned char key);

/* BRESENHAM */
void		bresenham_algorithm(mlx_image_t *image,
				int x0, int y0, int x1, int y1);

#endif
