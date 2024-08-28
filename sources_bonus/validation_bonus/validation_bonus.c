/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:31:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/08/28 12:22:56 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub_bonus.h"

void	validate_map(int argc, char **argv, t_cub *game)
{
	t_validate	valid;

	check_arguments(argc);
	check_extension(argv[1]);
	data_processing(argv[1], game->data);
	init_variables_valid(&valid);
	found_tabs(game->data);
	analyze_map_content(game->data, &valid);
	check_map_content(&valid);
	surrounded_by_walls(game->data);
}

void	check_arguments(int argc)
{
	if (argc < 2)
	{
		printf(WARNING_ARGS_1);
		free_memory(get_game(NULL));
		exit(EXIT_FAILURE);
	}
	else if (argc > 2)
	{
		printf(WARNING_ARGS_2);
		free_memory(get_game(NULL));
		exit(EXIT_FAILURE);
	}
	else
		return ;
}

void	check_extension(char *map_file)
{
	char	*dotcub;
	int		i;
	int		len;

	i = 0;
	dotcub = ".cub";
	len = ft_strlen(map_file);
	len = len - 4;
	while (map_file[len] && dotcub[i] && map_file[len] == dotcub[i])
	{
		i++;
		len++;
	}
	if (dotcub[i] == '\0')
		return ;
	handle_error(WARNING_EXT);
	exit(EXIT_FAILURE);
}

int	check_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
