#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../MLX42/include/MLX42/MLX42.h"

/* VECTORS */
void	setup(t_cub *game);
void	define_dir_vector(t_cub *game);

/* ALGORITHM */
void	draw_rays(t_cub *game);
void	calculate_delta_distance(t_cub *game);
void	calculate_distance_to_side(t_cub *game);
void	calculate_perpendicular_distance(t_cub *game);
void	dda_algorithm(t_cub *game);

/* DRAW LOOP */
void	draw(t_cub *game);
void	draw_wall(t_cub *game, int pixel);

#endif