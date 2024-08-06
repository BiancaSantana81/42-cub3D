#include "../includes/cub.h"

static void	aux_bresenham_algorithm(mlx_image_t *image, t_line *params, uint32_t color);

void	bresenham_algorithm(mlx_image_t *image, int x0, int y0, int x1, int y1)
{
	t_line		params;
	uint32_t	color;

	params.x0 = x0;
	params.y0 = y0;
	params.x1 = x1;
	params.y1 = y1;
	params.dx = abs(x1 - x0);
	params.dy = abs(y1 - y0);
	color = 0xFFFFFFF;
	params.dx = abs(params.x1 - params.x0);
	params.dy = abs(params.y1 - params.y0);
	if (params.x0 < params.x1)
		params.sx = 1;
	else
		params.sx = -1;
	if (params.y0 < params.y1)
		params.sy = 1;
	else
		params.sy = -1;
	params.err = params.dx - params.dy;
	aux_bresenham_algorithm(image, &params, color);
}

static void	aux_bresenham_algorithm(mlx_image_t *image, t_line *params, uint32_t color)
{
	int	e2;

	while (1)
	{
		if (params->x0 >= 0 && (uint32_t)params->x0 < image->width
			&& params->y0 >= 0 && (uint32_t)params->y0 < image->height)
			mlx_put_pixel(image, params->x0, params->y0, color);
		if (params->x0 == params->x1 && params->y0 == params->y1)
			break ;
		e2 = params->err * 2;
		if (e2 > -params->dy)
		{
			params->err -= params->dy;
			params->x0 += params->sx;
		}
		if (e2 < params->dx)
		{
			params->err += params->dx;
			params->y0 += params->sy;
		}
	}
}
