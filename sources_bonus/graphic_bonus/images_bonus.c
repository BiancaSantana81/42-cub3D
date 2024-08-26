/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:29:26 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:29:29 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	load_textures(t_cub *game)
{
	game->north = init_textures(game->data->no);
	game->south = init_textures(game->data->so);
	game->west = init_textures(game->data->we);
	game->east = init_textures(game->data->ea);
	game->player_1 = init_generic_images(game, "textures/player_1.png");
	game->player_2 = init_generic_images(game, "textures/player_2.png");
	game->player_2->image->enabled = false;
}

mlx_texture_t	*init_textures(char *path)
{
	mlx_texture_t	*images;

	images = mlx_load_png(path);
	if (!images)
		handle_error("Error: mlx_load_png failed");
	return (images);
}

t_images	*init_generic_images(t_cub *game, char *path)
{
	t_images	*sprite;

	sprite = ft_calloc(sizeof(t_images), 1);
	if (!sprite)
		return (NULL);
	sprite->texture = mlx_load_png(path);
	sprite->image = mlx_texture_to_image(game->mlx, sprite->texture);
	if (!sprite->image)
		return (NULL);
	mlx_resize_image
		(
			sprite->image,
			25 * 10,
			25 * 10
			);
	return (sprite);
}

uint32_t	get_texture_color(mlx_texture_t *texture, int y, int x)
{
	int		texture_pos;
	uint8_t	*pixel;

	if (x < 0 || x >= (int)texture->width || y < 0
		|| y >= (int)texture->height)
		return (0);
	texture_pos = y * texture->width + x;
	texture_pos *= texture->bytes_per_pixel;
	pixel = &texture->pixels[texture_pos];
	return (pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3]);
}

void	update_player(t_cub *game)
{
	static double	last_time;
	double			current_time;

	last_time = 0;
	current_time = mlx_get_time();
	if (game->keys.player)
	{
		game->player_1->image->enabled = false;
		game->player_2->image->enabled = true;
		last_time = current_time;
		if (current_time - last_time >= 0.5)
			game->keys.player = false;
	}
	if (!game->keys.player)
	{
		game->player_1->image->enabled = true;
		game->player_2->image->enabled = false;
	}
}
