#ifndef STRUCTS_H
# define STRUCTS_H

# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_data
{
	int				size_textures;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	bool			colors;
	uint32_t		floor;
	uint32_t		ceiling;
	char			**map;
	int				lines;
	int				columns;
}	t_data;

typedef struct s_validate
{
	int		invalid;
	int		player;
	int		n;
	char	pos_player;
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
