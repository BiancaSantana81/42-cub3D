#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../MLX42/include/MLX42/MLX42.h"

/* VECTORS */
void	setup(t_cub *game);

/* ALGORITHM */
void	draw_rays(t_cub *game);
void	calculate_delta_distance(t_dda *ray);
void	calculate_distance_to_side(t_dda *ray, t_cub *game);
void	dda_algorithm(t_dda *ray, t_cub *game);
void	update_fps(t_cub *game);


/* DRAW LOOP */
void	draw_playerview(void *param);
void	draw_wall(t_dda *ray, t_cub *game, int pixel);

#endif