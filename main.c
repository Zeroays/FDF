/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:12:20 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 22:18:36 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdf	*wireframe;
	char	*extension;

	wireframe = NULL;
	if (argc == 2)
	{
		if (!(extension = ft_strchr(argv[1], '.')))
			fdf_exit(NO_EXT);
		if (ft_strcmp(extension, ".fdf"))
			fdf_exit(INVALID_EXT);
		wireframe = orc(argv);
		wireframe->display.init = mlx_init();
		wireframe->display.win = mlx_new_window(wireframe->display.init, \
		HEIGHT, WIDTH, TITLE);
		reset(wireframe);
		instructions(wireframe);
		mlx_hook(wireframe->display.win, KEY_PRESS, 1, key_press, wireframe);
		mlx_hook(wireframe->display.win, X_BUTTON, 1, terminate, wireframe);
		mlx_loop(wireframe->display.init);
	}
	else
		fdf_exit(DNE);
}
