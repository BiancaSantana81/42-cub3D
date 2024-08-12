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
	t_vector		pos; //posicao do player
	t_vector		dir; //direcao do player
	t_vector		camera_plane; //plano da camera
	t_vector		camera_pixel;//vetor que liga ray_dir e dir (conecta a ponta dos dois vetores)
	t_vector		ray_dir; // raio que sai do player
	t_vector		delta_dist; //depois de dist_to_side_x e dist_to_side_y até o próximo encontro com x ou y
	t_vector		map_pos; //posicao no mapa
	t_vector		wall_map_pos; //posicao (y,x) da parede no mapa conforme o algoritmo vai calculando se bateu na parede
	float			dist_to_side_x; //distancia para o proximo lado em x
	float			dist_to_side_y; //distancia para o proximo lado em y
	int				step_x; //passos dados em x
	int				step_y; //passos dados em y
	int				dda_line_side_x; //tamanho da coluna formada durante o dda
	int				dda_line_side_y; //tamanho da linha formada durante o dda
	int				hit_side; //lado que bateu
	bool			hit; //se bateu na parede
	float			perp_dist; //distancia do plano de camera ate a parede
	int				wall_height; //altura da parede
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
	IMAGE_TO_WINDOW,
}	t_mlx_action;

#endif
