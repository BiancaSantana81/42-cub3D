/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:25:59 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:26:04 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	process_input(t_cub *game)
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

int	get_signal(float value)
{
	if (value < 0)
		return (-1);
	return (1);
}

bool	can_move_to(t_cub *game, float new_x, float new_y)
{
	float		margin;

	margin = 0.1;
	if (game->data->map[(int)(new_y + margin
			* get_signal(game->dir.y))][(int)new_x] == '1')
		return (false);
	if (game->data->map[(int)new_y][(int)(new_x + margin
			* get_signal(game->dir.x))] == '1')
		return (false);
	if (game->data->map[(int)(new_y + margin
			* get_signal(game->camera_plane.y))][(int)new_x] == '1')
		return (false);
	if (game->data->map[(int)new_y][(int)(new_x + margin
			* get_signal(game->camera_plane.x))] == '1')
		return (false);
	return (true);
}

void	calculate_new_position(t_cub *game, float *new_x, float *new_y)
{
	float	move_speed;

	move_speed = game->frame_time * 4;
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
