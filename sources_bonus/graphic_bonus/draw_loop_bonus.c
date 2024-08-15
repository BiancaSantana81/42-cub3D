#include "../../includes_bonus/cub_bonus.h"

void	draw_playerview(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	process_input(game);
	draw_background(game);
	update_fps(game);
	draw_rays(game);
}
