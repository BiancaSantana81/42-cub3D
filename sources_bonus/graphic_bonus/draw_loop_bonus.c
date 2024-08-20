#include "../../includes_bonus/cub_bonus.h"

void	draw_playerview(void *param)
{
	t_cub	*game;
	int32_t	x;
	int32_t	y;

	game = (t_cub *)param;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	update_fps(game);
	update_player(game);
	draw_minimap(game);
	update_minimap(game);
	process_input(game, x);
	draw_background(game);
	draw_rays(game);
}
