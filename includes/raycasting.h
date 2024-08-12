#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "../MLX42/include/MLX42/MLX42.h"

/* VECTORS */
void		setup(t_cub *game);
void		define_dir_vector(t_cub *game);

/* ALGORITHM */
void		draw(t_cub *game);
void		draw_rays(t_cub *game);

#endif