/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:15:08 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/02 11:03:36 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "keys.h"
# include "display.h"
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <errno.h>

# define COL_DIGIT_ERR 4
# define OPEN_ERR 2
# define CLOSE_ERR 9
# define DNE 5
# define MALLOC_ERR 6
# define INVALID_EXT 8
# define EMPTY 10
# define NO_EXT 11

# define USAGE "./fdf fdf_file"
# define OPEN_CLOSE_ERR "OPEN/CLOSE ERROR : "

# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define ABS(X) ((X) < 0 ? -(X) : (X))

typedef struct		s_mlx
{
	void			*init;
	void			*win;
}					t_mlx;

typedef struct		s_fdf
{
	t_mlx			display;
	int				**map;
	int				map_row;
	int				map_col;
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z0;
	int				z1;
	int				x_shift;
	int				y_shift;
	unsigned int	color;
	int				camera;
	double			xy_zoom;
	double			z_zoom;
}					t_fdf;

int					fdf_exit(int code);
int					data_check(char *line);
void				map_store(char *line, t_fdf *fdf, int cnt);
int					**validate(char *argv);
t_fdf				*orc(char **argv);
t_fdf				*setup(char *argv);
void				arr_free(void **arr, size_t rows, int dp);
void				iso(int *x, int *y, int z);
void				military(int *x, int *y, int z);
int					key_press(int keycode, t_fdf *wireframe);
int					terminate(t_fdf *wireframe);
void				rasterization(t_fdf *wire);
void				v(t_fdf *wire, int x, int y, void (*f)(int *, int *, int));
void				h(t_fdf *wire, int x, int y, void (*f)(int *, int *, int));
void				bresenham(t_fdf *wire);
void				reset(t_fdf *fdf);
void				print_the_grid(t_fdf *fdf);
void				spike(t_fdf *wireframe, int direction);
void				zoom_io(t_fdf *wireframe, int direction);
void				rand_color(t_fdf *wireframe);
void				shift(t_fdf *wireframe, char direction);
void				camera_change(t_fdf *wireframe);
void				instructions(t_fdf *wireframe);
#endif
