#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

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
	char			pos_player;
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

typedef struct s_cub
{
	mlx_t			*mlx;
	mlx_image_t		*mlx_image;
	mlx_image_t		*map_image;
	mlx_image_t		*line_image;
	t_images		*player;
	t_images		*north;
	t_images		*south;
	t_images		*west;
	t_images		*east;
	struct s_data	*data;

}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
	IMAGE_TO_WINDOW,
}	t_mlx_action;

#endif
