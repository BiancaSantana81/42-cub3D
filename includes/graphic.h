#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"

/* HOOKS */
int32_t		key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2);
void		hook_key_press(mlx_key_data_t keydata, void *param);
void		hook_close(void *param);
void		calculate_window_size(t_cub *game);

/* IMAGES */
t_images	*init_images(t_cub *game, char *path);
void		free_sprite(t_cub *game, t_images *image);
void		load_textures(t_cub *game);
void		draw_images(t_cub *game);


void	draw_player_square(t_cub *game);
void	draw_square(t_cub *game, int start_x, int start_y, int size, uint32_t color);
void	draw_map(t_cub *game);

#endif