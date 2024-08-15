#include "../../includes/cub.h"

void	process_input(t_cub *game)
{
	float	new_x;
	float	new_y;

	calculate_new_position(game, &new_x, &new_y);
	// acho que os valores setados como true tem que ser dentro de calculate new_postion n? já que são eles que fazem o calculo de quanto aumentar na mov
	if (can_move_to(game, new_x, new_y))
	{
		printf("oi\n");
		game->pos.x = new_x;
		game->pos.y = new_y;
	}
	if (game->keys.left)
	{
		game->dir = rotate_vector(game->dir, -1.5);
		game->camera_plane = rotate_vector(game->camera_plane, -1.5);
	}
	if (game->keys.right)
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
	*new_x = game->pos.x;
	*new_y = game->pos.y;
	if (game->keys.w)
	{
		*new_x += game->dir.x * MOVE_SPEED;
		*new_y += game->dir.y * MOVE_SPEED;
	}
	if (game->keys.s)
	{
		*new_x -= game->dir.x * MOVE_SPEED;
		*new_y -= game->dir.y * MOVE_SPEED;
	}
	if (game->keys.a)
	{
		*new_x -= game->camera_plane.x * MOVE_SPEED;
		*new_y -= game->camera_plane.y * MOVE_SPEED;
	}
	if (game->keys.d)
	{
		*new_x += game->camera_plane.x * MOVE_SPEED;
		*new_y += game->camera_plane.y * MOVE_SPEED;
	}
}
