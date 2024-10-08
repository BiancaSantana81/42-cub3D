/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:28:00 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/20 14:28:06 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	t_cub	game;

	init_cub(&game);
	validate_map(argc, argv, &game);
	init_game(&game);
	return (EXIT_SUCCESS);
}

int	init_game(t_cub *game)
{
	handle_mlx_actions(INIT, game);
	handle_mlx_actions(NEW_IMAGE, game);
	load_textures(game);
	setup(game);
	mlx_key_hook(game->mlx, hook_key_press, game);
	mlx_loop_hook(game->mlx, draw_playerview, game);
	mlx_close_hook(game->mlx, hook_close, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}

void	handle_mlx_actions(int action, t_cub *game)
{
	if (action == INIT)
	{
		mlx_set_setting(MLX_STRETCH_IMAGE, true);
		game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", true);
		if (!game->mlx)
			handle_error("Error: mlx_init failed.");
	}
	else if (action == NEW_IMAGE)
	{
		game->mlx_image = mlx_new_image(game->mlx, WIDTH, HEIGHT);
		if (!game->mlx_image)
			handle_error("Error open window.\n");
		if (mlx_image_to_window(game->mlx, game->mlx_image, 0, 0) < 0)
			handle_error("Error mlx_image_to_window.\n");
	}
}
