#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/src/libft.h"

typedef struct s_data
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	bool			colors;
	uint32_t		floor;
	uint32_t		ceiling;
	int				size_textures;
	int				lines;
	int				columns;
	int				x_player;
	int				y_player;
	char			pov_player;
}	t_data;

typedef struct s_validate
{
	int		invalid;
	int		player;
	int		n;
}	t_validate;

typedef struct s_images
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				x;
	int				y;
}	t_images;

typedef struct s_line
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;
}	t_line;

// typedef struct s_vector
// {
// 	float	x;
// 	float	y;
// }	t_vector;

typedef struct s_cub
{
	uint32_t		window_width;
	uint32_t		window_height;
	mlx_t			*mlx;
	mlx_image_t		*background_image;
	mlx_image_t		*mlx_image;
	mlx_image_t		*map_image;
	mlx_image_t		*line_image;
	t_vector		pos;
	t_vector		dir;
	t_vector		camera_plane;
	t_vector		camera_pixel;
	t_vector		ray_dir;
	t_vector		delta_dist;
	t_vector		map_pos;
	float			dist_to_side_x;
	float			dist_to_side_y;
	int				step_x;
	int				step_y;
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
	IMAGE_TO_WINDOW,
}	t_mlx_action;

#endif
