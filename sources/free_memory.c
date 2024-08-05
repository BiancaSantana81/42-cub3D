#include "../includes/cub.h"

void	free_data(t_data *data)
{
	if (data->no)
		free(data->no);
	if (data->so)
		free(data->so);
	if (data->we)
		free(data->we);
	if (data->ea)
		free(data->ea);
	if (data->map)
		ft_free_matrix(data->map);
	if (data)
		free(data);
}

void	free_memory(t_cub *game)
{
	if (game)
		free_data(game->data);
}

void	free_sprite(t_cub *game, t_images *image)
{
	mlx_delete_image(game->mlx, image->img);
	mlx_delete_texture(image->texture);
	free(image);
}
