#include "../../includes_bonus/cub_bonus.h"


void	draw_playerview(void *param)
{
	t_cub	*game;

	game = (t_cub *)param;
	update_fps(game);
	draw_minimap(game);
	update_minimap(game);
	process_input(game);
	draw_background(game);
	draw_rays(game);
}
