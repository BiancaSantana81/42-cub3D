#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"

/* HOOKS */
int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2);
void	ft_hooks(mlx_key_data_t keydata, void *param);
void	free_and_close(void *param);
void	draw_example_pixel(t_cub *game);
void	draw_grid(t_cub *game);
void    draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1, uint32_t color);
void	calculate_window_size(t_data *data);

#endif