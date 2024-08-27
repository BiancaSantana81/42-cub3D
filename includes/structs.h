/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:23:02 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:23:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_keys
{
	bool	w;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
}	t_keys;

typedef struct s_validate
{
	int		invalid;
	int		player;
}	t_validate;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_dda
{
	float		plane_multiplier;
	t_vector	dir;
	t_vector	camera_pixel;
	t_vector	delta_dist;
	t_vector	dist_side;
	t_coord		map;
	t_coord		step;
	int			hit_side;
	float		perp_dist;
	float		wall_hit_x;
}	t_dda;

typedef struct s_wall
{
	int		height;
	int		line_start_y;
	int		line_end_y;
	int		texture_x;
	int		texture_y;
	float	point_x;
	float	texture_step;
	float	texture_pos;
}	t_wall;

typedef struct s_cub
{
	mlx_t			*mlx;
	t_keys			keys;
	mlx_image_t		*mlx_image;
	mlx_texture_t	*texture;
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*east;
	int				*texture_buffer[4];
	t_vector		pos;
	t_vector		dir;
	t_vector		camera_plane;
	int				hit_side;
	float			frame_time;
	t_data			*data;
}	t_cub;

typedef enum e_mlx_action
{
	INIT,
	NEW_IMAGE,
}	t_mlx_action;

#endif
