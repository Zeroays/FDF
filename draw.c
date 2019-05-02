/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:15:51 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 21:58:43 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_fdf *wire)
{
	int		x0;
	int		y0;
	int		dxy[2];
	int		sxy[2];
	int		e[2];

	x0 = wire->x0;
	y0 = wire->y0;
	sxy[0] = ABS(wire->x1 - x0);
	sxy[1] = ABS(wire->y1 - y0);
	dxy[0] = x0 < wire->x1 ? 1 : -1;
	dxy[1] = y0 < wire->y1 ? 1 : -1;
	e[0] = (sxy[0] > sxy[1] ? sxy[0] : -sxy[1]) / 2;
	while (x0 != wire->x1 || y0 != wire->y1)
	{
		mlx_pixel_put(wire->display.init, wire->display.win, \
		x0, y0, wire->color);
		e[1] = e[0];
		e[1] > -sxy[0] ? e[0] -= sxy[1] : 1 == 1;
		e[1] > -sxy[0] ? x0 += dxy[0] : 1 == 1;
		e[1] < sxy[1] ? e[0] += sxy[0] : 1 == 1;
		e[1] < sxy[1] ? y0 += dxy[1] : 1 == 1;
	}
}

void	h(t_fdf *wire, int x, int y, void (*f)(int *, int *, int))
{
	int		max;

	max = MIN((HEIGHT / wire->map_row), (WIDTH / wire->map_col));
	wire->x0 = x - wire->map_col / 2;
	wire->y0 = -y + wire->map_row / 2;
	wire->z0 = wire->map[y][x] * max * wire->z_zoom;
	wire->z1 = wire->map[y][x + 1] * max * wire->z_zoom;
	wire->x1 = wire->x0 + 1;
	wire->y1 = wire->y0;
	wire->x0 *= max * wire->xy_zoom;
	wire->x1 *= max * wire->xy_zoom;
	wire->y0 *= max * wire->xy_zoom;
	wire->y1 *= max * wire->xy_zoom;
	f(&wire->x0, &wire->y0, wire->z0);
	f(&wire->x1, &wire->y1, wire->z1);
	wire->x0 += (WIDTH) + wire->x_shift;
	wire->x1 += (WIDTH) + wire->x_shift;
	wire->y0 += (HEIGHT / 3.5) + wire->y_shift;
	wire->y1 += (HEIGHT / 3.5) + wire->y_shift;
	bresenham(wire);
}

void	v(t_fdf *wire, int x, int y, void (*f)(int *, int *, int))
{
	int		max;

	max = MIN((HEIGHT / wire->map_row), (WIDTH / wire->map_col));
	wire->x0 = x - wire->map_col / 2;
	wire->y0 = -y + wire->map_row / 2;
	wire->z0 = wire->map[y][x] * max * wire->z_zoom;
	wire->z1 = wire->map[y + 1][x] * max * wire->z_zoom;
	wire->x1 = wire->x0;
	wire->y1 = wire->y0 - 1;
	wire->x0 *= max * wire->xy_zoom;
	wire->x1 *= max * wire->xy_zoom;
	wire->y0 *= max * wire->xy_zoom;
	wire->y1 *= max * wire->xy_zoom;
	f(&wire->x0, &wire->y0, wire->z0);
	f(&wire->x1, &wire->y1, wire->z1);
	wire->x0 += (WIDTH) + wire->x_shift;
	wire->x1 += (WIDTH) + wire->x_shift;
	wire->y0 += (HEIGHT / 3.5) + wire->y_shift;
	wire->y1 += (HEIGHT / 3.5) + wire->y_shift;
	bresenham(wire);
}

void	rasterization(t_fdf *wire)
{
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(wire->display.init, wire->display.win);
	while (y < wire->map_row)
	{
		x = 0;
		while (x < wire->map_col)
		{
			(x + 1 < wire->map_col && wire->camera == 1) ? \
			h(wire, x, y, iso) : x;
			(x + 1 < wire->map_col && wire->camera == 0) ? \
			h(wire, x, y, military) : x;
			(y + 1 < wire->map_row && wire->camera == 1) ? \
			v(wire, x, y, iso) : y;
			(y + 1 < wire->map_row && wire->camera == 0) ? \
			v(wire, x, y, military) : y;
			x++;
		}
		y++;
	}
}
