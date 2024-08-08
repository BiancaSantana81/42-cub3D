#include "../includes/cub.h"
# define WIDTH 320

// nós devemos criar um raio para cada pixel
// para o cáculo dos raios é DIR + PLANE * -1 pra direira e DIR + PLANE * 1 para esquerda.

void	draw_rays(t_cub *game)
{
	int	i;

	i =  0;
	while (i < WIDTH)
	{
		ray();
		i++;
	}
}
