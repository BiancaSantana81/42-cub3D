#include "../../includes/cub.h"
 
void	update_fps(t_cub *game)
{
	char				*fps_nbr;
	char				*fps_txt;
	static int			fps_len;
	static mlx_image_t	*fps_image;

	if (fps_len % 15 == 0)
	{
		game->frame_time = game->mlx->delta_time;
		if (fps_image)
			mlx_delete_image(game->mlx, fps_image);
		fps_nbr = ft_itoa(1 / game->mlx->delta_time);
		fps_txt = ft_strjoin("FPS: ", fps_nbr);
		free(fps_nbr);
		fps_image = mlx_put_string(game->mlx, fps_txt, WIDTH - 80, HEIGHT - 590);
		free(fps_txt);
	}
}