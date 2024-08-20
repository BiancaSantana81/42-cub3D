/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_squares_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:29:04 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:29:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	draw_background(t_cub *game)
{
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < game->mlx_image->height / 2)
	{
		x = 0;
		while (x < game->mlx_image->width)
		{
			mlx_put_pixel(game->mlx_image, x, y, game->data->ceiling);
			x++;
		}
		y++;
	}
	while (y < game->mlx_image->height)
	{
		x = 0;
		while (x < game->mlx_image->width)
		{
			mlx_put_pixel(game->mlx_image, x, y, game->data->floor);
			x++;
		}
		y++;
	}
}
