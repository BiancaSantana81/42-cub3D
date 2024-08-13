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

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

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

typedef struct s_dda
{
	float		plane_multiplier;
	t_vector	dir; //raio que sai do player
	t_vector	camera_pixel; //distancia de dir para raydir
	t_vector	delta_dist; //depois de dist_to_side_x e dist_to_side_y até o próximo encontro com x ou y
	t_vector	dist_side; //distancia ate o proximo lado em x ou y
	t_coord		map; //posicao no mapa
	t_coord		step; //passos dados em x e y
	int			hit_side; //lado que bateu
	float		perp_dist; //distancia do plano de camera ate a parede
}	t_dda;

typedef struct s_cub
{
	uint32_t		window_width;
	uint32_t		window_height;
	mlx_t			*mlx;
	mlx_image_t		*background_image;
	mlx_image_t		*mlx_image;
	mlx_image_t		*map_image;
	mlx_image_t		*line_image;
	mlx_image_t		*walls_image;
	t_images		*north;
	t_images		*south;
	t_images		*west;
	t_images		*east;
	t_vector		pos; //posicao do player
	t_vector		dir; //direcao do player
	t_vector		camera_plane; //plano da camera
	int				hit_side; //lado que bateu
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
}	t_mlx_action;

#endif
