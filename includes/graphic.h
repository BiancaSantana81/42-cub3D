#ifndef GRAPHIC_H
# define GRAPHIC_H

# include "../MLX42/include/MLX42/MLX42.h"

/* HOOKS */
int32_t	key_pressed(mlx_key_data_t keydata, keys_t key1, keys_t key2);
void	ft_hooks(mlx_key_data_t keydata, void *param);
void	free_and_close(void *param);
void    ft_randomize(void* param);
void	draw_example_pixel(t_cub *game);

#endif