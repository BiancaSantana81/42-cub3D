#include "../includes/cub.h"

void	draw_line(mlx_image_t *image, int x0, int y0)
{
	t_line	draw;

	draw.x0 = x0;
	draw.y0 = y0;
	draw.dx = abs(120 - x0);
	draw.dy = abs(120 - y0);
	if (x0 < 120)
		draw.sx = 1;
	else
		draw.sx = -1;
	if (y0 < 120)
		draw.sy = 1;
	else
		draw.sy = -1;
	draw.err = draw.dx - draw.dy;
	aux_draw_line(image, &draw);
}

void	aux_draw_line(mlx_image_t *image, t_line *draw)
{
	int	e2;

	while (1)
	{
		if (draw->x0 >= 0 && (uint32_t)draw->x0 < image->width
			&& draw->y0 >= 0 && (uint32_t)draw->y0 < image->height)
			mlx_put_pixel(image, draw->x0, draw->y0, 0xFFFFFFF);
		if (draw->x0 == 120 && draw->y0 == 120)
			break ;
		e2 = draw->err * 2;
		if (e2 > -draw->dy)
		{
			draw->err -= draw->dy;
			draw->x0 += draw->sx;
		}
		if (e2 < draw->dx)
		{
			draw->err += draw->dx;
			draw->y0 += draw->sy;
		}
	}
}
