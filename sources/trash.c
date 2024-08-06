#include "../includes/cub.h"

void	print_data(t_data data)
{
	printf("NO: %s\n", data.no);
	printf("SO: %s\n", data.so);
	printf("WE: %s\n", data.we);
	printf("EA: %s\n", data.ea);
	printf("F: %u\n", data.floor);
	printf("C: %u\n", data.ceiling);
	ft_print_matrix(data.map);
}
// organizar norminette
// void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1)
// {
// 	int			sx;
// 	int			sy;
// 	int			dx;
// 	int			dy;
// 	int			err;
// 	int			e2;
// 	uint32_t	color;

// determinam a inclinação da linha usando a substração de x1 - x0 (com valores absolutos)
// 	dx = abs(x1 - x0);
// 	dy = abs(y1 - y0);
// 	color = 0xFFFFFFF;
// 	// verificações determinam para qual direção a linha deve ser desenhada
// 	if (x0 < x1)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (y0 < y1)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	// ajuda a ajustar a posição do ponto na direção x ou y para manter a linha o mais próximo possível da trajetória incial
// 	err = dx - dy;
// 	while (1)
// 	{
// 		if (x0 >= 0 && (uint32_t)x0 < image->width
// 			&& y0 >= 0 && (uint32_t)y0 < image->height)
// 			mlx_put_pixel(image, x0, y0, color);
// 		if (x0 == x1 && y0 == y1)
// 			break ;
// 		// valor de err é multiplicado por 2 para trabalhar com valores inteiros.
// 		e2 = err * 2;
// 		// avalia qual a direção as coordenadas devem ser acumuladas de acordo com o valor de e2
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x0 += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y0 += sy;
// 		}
// 	}
// }

// void	bresenham_algorithm(mlx_image_t *image, int x0, int y0, int x1, int y1)
// {
// 	t_line		*params;
// 	uint32_t	color;

// 	params->x0 = x0;
// 	params->y0 = y0;
// 	params->x1 = x1;
// 	params->y1 = y1;
// 	// determinam a inclinação da linha usando a substração de x1 - x0 (com valores absolutos)
// 	params->dx = abs(x1 - x0);
// 	params->dy = abs(y1 - y0);
// 	color = 0xFFFFFFF;
// 	params->dx = abs(params->x1 - params->x0);
// 	params->dy = abs(params->y1 - params->y0);
// 	if (params->x0 < params->x1)
// 		params->sx = 1;
// 	else
// 		params->sx = -1;
// 	if (params->y0 < params->y1)
// 		params->sy = 1;
// 	else
// 		params->sy = -1;
// 	// ajuda a ajustar a posição do ponto na direção x ou y para manter a linha o mais próximo possível da trajetória incial
// 	params->err = params->dx - params->dy;
// 	aux_bresenham_algorithm(image, &params, color);
// }

// static void	aux_bresenham(mlx_image_t *image, t_line *params, uint32_t color)
// {
// 	int	e2;

// 	while (1)
// 	{
// 		if (params->x0 >= 0 && (uint32_t)params->x0 < image->width
// 			&& params->y0 >= 0 && (uint32_t)params->y0 < image->height)
// 			mlx_put_pixel(image, params->x0, params->y0, color);
// 		if (params->x0 == params->x1 && params->y0 == params->y1)
// 			break ;
// 		e2 = params->err * 2;
// 		// avalia qual a direção as coordenadas devem ser acumuladas de acordo com o valor de e2
// 		if (e2 > -params->dy)
// 		{
// 			params->err -= params->dy;
// 			params->x0 += params->sx;
// 		}
// 		if (e2 < params->dx)
// 		{
// 			params->err += params->dx;
// 			params->y0 += params->sy;
// 		}
// 	}
// }
