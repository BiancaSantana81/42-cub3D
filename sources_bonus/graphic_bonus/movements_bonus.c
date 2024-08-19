#include "../../includes_bonus/cub_bonus.h"

void	process_input(t_cub *game, int32_t x)
{
	float	new_x;
	float	new_y;
	
	new_x = 0;
	new_y = 0;
	calculate_new_position(game, &new_x, &new_y);
	if (can_move_to(game, new_x, new_y))
	{
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
	if (game->keys.left || x < 300)
	{
		game->dir = rotate_vector(game->dir, -1.5);
		game->camera_plane = rotate_vector(game->camera_plane, -1.5);
	}
	if (game->keys.right || x > 500)
	{
		game->dir = rotate_vector(game->dir, 1.5);
		game->camera_plane = rotate_vector(game->camera_plane, 1.5);
	}
}

bool	can_move_to(t_cub *game, float new_x, float new_y)
{
	if (game->data->map[(int)new_y][(int)new_x] == '1')
		return (false);
	return (true);
}

void	calculate_new_position(t_cub *game, float *new_x, float *new_y)
{
	float	move_speed;

	move_speed = game->frame_time * 6;
	*new_x = game->pos.x;
	*new_y = game->pos.y;
	if (game->keys.w == true)
	{
		*new_x += game->dir.x * move_speed;
		*new_y += game->dir.y * move_speed;
	}
	if (game->keys.s == true)
	{
		*new_x -= game->dir.x * move_speed;
		*new_y -= game->dir.y * move_speed;
	}
	if (game->keys.a == true)
	{
		*new_x -= game->camera_plane.x * move_speed;
		*new_y -= game->camera_plane.y * move_speed;
	}
	if (game->keys.d == true)
	{
		*new_x += game->camera_plane.x * move_speed;
		*new_y += game->camera_plane.y * move_speed;
	}
}
