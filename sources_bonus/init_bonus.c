/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:31:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:31:34 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub_bonus.h"

void	init_cub(t_cub *game)
{
	game->mlx = NULL;
	game->map_image = NULL;
	game->frame_time = 0;
	game->keys.w = false;
	game->keys.s = false;
	game->keys.a = false;
	game->keys.d = false;
	game->keys.left = false;
	game->keys.right = false;
	game->keys.minimap = false;
	game->keys.player = false;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->east = NULL;
	game->player_1 = NULL;
	game->player_2 = NULL;
	game->data = ft_calloc(1, sizeof(t_data));
	init_data(game);
	get_game(game);
}

void	init_data(t_cub *game)
{
	game->data->size_textures = 0;
	game->data->no = NULL;
	game->data->so = NULL;
	game->data->we = NULL;
	game->data->ea = NULL;
	game->data->map = NULL;
	game->data->y_player = 0;
	game->data->x_player = 0;
	game->data->colors = false;
	game->data->floor = 0;
	game->data->ceiling = 0;
}

void	init_variables_valid(t_validate *valid)
{
	valid->invalid = 0;
	valid->player = 0;
	valid->n = 0;
}
