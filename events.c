/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 12:31:50 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 22:21:51 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, t_fdf *wireframe)
{
	if (keycode == ESC)
		terminate(wireframe);
	else if (keycode == RESET)
		reset(wireframe);
	else if (keycode == COLOR)
		rand_color(wireframe);
	else if (keycode == ELEVATION)
		spike(wireframe, 1);
	else if (keycode == DE_ELEVATION)
		spike(wireframe, -1);
	else if (keycode == ZOOM_IN)
		zoom_io(wireframe, 1);
	else if (keycode == ZOOM_OUT)
		zoom_io(wireframe, -1);
	else if (keycode == LEFT)
		shift(wireframe, 'l');
	else if (keycode == RIGHT)
		shift(wireframe, 'r');
	else if (keycode == UP)
		shift(wireframe, 'u');
	else if (keycode == DOWN)
		shift(wireframe, 'd');
	else if (keycode == PROJECTION)
		camera_change(wireframe);
	return (0);
}

int		terminate(t_fdf *wireframe)
{
	arr_free((void **)wireframe->map, wireframe->map_row, 0);
	free(wireframe);
	exit(0);
	return (0);
}
