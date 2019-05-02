/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 14:04:07 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 23:05:01 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	instructions(t_fdf *wireframe)
{
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 50, HEIGHT / 80, 0x00FFFFFF, "Controls:");
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 15, HEIGHT / 40, 0x00FFFFFF, "Zoom >> +/-");
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 15, HEIGHT / 25, 0x00FFFFFF, "Translate >> WASD");
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 15, HEIGHT / 18, 0x00FFFFFF, "Color >> C");
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 15, HEIGHT / 14, 0x00FFFFFF, "Spike Up/Down >> F/G");
	mlx_string_put(wireframe->display.init, wireframe->display.win, \
	WIDTH / 15, HEIGHT / 11.5, 0x00FFFFFF, "Projection >> P");
}

int		fdf_exit(int code)
{
	if (code == NO_EXT)
		ft_putstr_fd("File has no extension\n", 0);
	else if (code == INVALID_EXT)
		ft_putstr_fd("Invalid Extension...\n", 0);
	else if (code == COL_DIGIT_ERR)
		ft_putstr_fd("File Contents are not valid.  Try another...\n", 0);
	else if (code == MALLOC_ERR)
		ft_putstr_fd("Malloc error.  Abort...\n", 0);
	else if (code == EMPTY)
		ft_putstr_fd("File is empty.  Try another one\n", 0);
	else if (code == OPEN_ERR || code == CLOSE_ERR)
	{
		ft_putstr_fd(strerror(errno), 0);
		ft_putstr_fd("\n", 0);
	}
	exit(code);
}

void	arr_free(void **arr, size_t rows, int dp)
{
	size_t i;

	i = 0;
	while (i < rows)
	{
		ft_memdel((void **)(&arr[i]));
		i++;
	}
	(dp) ? free(arr) : dp;
}

void	reset(t_fdf *wireframe)
{
	wireframe->color = 0x00FFFFFF;
	wireframe->camera = 1;
	wireframe->z_zoom = Z_ZOOM;
	wireframe->xy_zoom = 1;
	wireframe->x_shift = 0;
	wireframe->y_shift = 0;
	wireframe->camera = 1;
	rasterization(wireframe);
	instructions(wireframe);
}
