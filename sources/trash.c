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
void	draw_line(mlx_image_t *image, int x0, int y0, int x1, int y1)
{
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			err;
	int			e2;
	uint32_t	color;

	dx = abs(x0 - x1);
	dy = abs(y0 - y1);
	color = 0xFFFFFFF;
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		if (x0 >= 0 && (uint32_t)x0 < image->width
			&& y0 >= 0 && (uint32_t)y0 < image->height)
			mlx_put_pixel(image, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err * 2;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
