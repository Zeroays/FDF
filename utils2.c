/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:04:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 22:23:48 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	spike(t_fdf *wireframe, int direction)
{
	if (direction < 0)
		wireframe->z_zoom += Z_ZOOM;
	else
		wireframe->z_zoom -= Z_ZOOM;
	rasterization(wireframe);
	instructions(wireframe);
}

void	zoom_io(t_fdf *wireframe, int direction)
{
	if (direction < 0)
		wireframe->xy_zoom += XY_ZOOM;
	else if (wireframe->xy_zoom >= XY_ZOOM)
		wireframe->xy_zoom -= XY_ZOOM;
	rasterization(wireframe);
	instructions(wireframe);
}

void	rand_color(t_fdf *wireframe)
{
	wireframe->color = rand() % 0x00FFFFFF;
	rasterization(wireframe);
	instructions(wireframe);
}

void	shift(t_fdf *wireframe, char direction)
{
	if (direction == 'u')
		wireframe->y_shift -= 5;
	else if (direction == 'd')
		wireframe->y_shift += 5;
	else if (direction == 'l')
		wireframe->x_shift -= 5;
	else if (direction == 'r')
		wireframe->x_shift += 5;
	rasterization(wireframe);
	instructions(wireframe);
}

void	camera_change(t_fdf *wireframe)
{
	if (wireframe->camera == 0)
		wireframe->camera = 1;
	else if (wireframe->camera == 1)
		wireframe->camera = 0;
	rasterization(wireframe);
	instructions(wireframe);
}
