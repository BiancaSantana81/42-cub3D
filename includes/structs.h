#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	int		size_textures;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	uint32_t		floor;
	uint32_t		ceiling;
	char	**map;
}	t_data;

typedef struct s_validate
{
	int		invalid; //se tiver caracter invalido
	int		player; // somar se for E, N, S ou W
	int		n; //se houver /n no meio do mapa
	char	pos_player; //para onde o player esta apontando
	char	**clone_map; // cópia do mapa para validar flood fill
	int		lines; // checar no flood fill;
	int		columns; // checar no flood fill;
}	t_validate;

typedef struct s_cub
{
	mlx_t			*mlx;
	struct s_data	*data;

}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
	IMAGE_TO_WIDOW,
}	t_mlx_action;

#endif
