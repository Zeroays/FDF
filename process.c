/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:12:50 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/02 11:15:25 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		data_check(char *line)
{
	int	len;
	int	i;
	int	col;

	len = ft_strlen(line);
	i = 0;
	col = 0;
	while (i < len)
	{
		if (ft_isdigit(line[i]))
		{
			col += 1;
			while (ft_isdigit(line[i]))
				i++;
		}
		else if (line[i] != ' ' && line[i] != '-')
			return (0);
		i++;
	}
	return (col);
}

int		**validate(char *argv)
{
	int		**tmp;
	int		fd;
	int		row;
	int		col;
	char	*line;

	row = 0;
	((fd = open(argv, O_RDONLY)) < 0) ? fdf_exit(OPEN_ERR) : fd;
	while (get_next_line(fd, &line) == 1)
	{
		(!(col)) ? col = data_check(line) : col;
		if (col != data_check(line) || (col <= 0))
		{
			free(line);
			fdf_exit(COL_DIGIT_ERR);
		}
		row++;
		free(line);
	}
	(close(fd) == -1) ? fdf_exit(CLOSE_ERR) : fd;
	tmp = ft_intnew(1, 2);
	tmp[0][0] = row;
	tmp[0][1] = col;
	return (tmp);
}

void	map_store(char *line, t_fdf *fdf, int cnt)
{
	int		x;
	int		num;
	char	**c_data;

	x = 0;
	if (!(c_data = ft_strsplit(line, ' ')))
		fdf_exit(MALLOC_ERR);
	while (x < fdf->map_col)
	{
		num = ft_atoi(c_data[x]);
		fdf->map[cnt][x] = num;
		x++;
	}
	arr_free((void **)c_data, (size_t)fdf->map_col, 1);
}

t_fdf	*setup(char *argv)
{
	t_fdf	*fdf;
	int		row;
	int		col;
	int		**tmp;

	fdf = NULL;
	tmp = validate(argv);
	row = tmp[0][0];
	col = tmp[0][1];
	arr_free((void **)tmp, 1, 1);
	if (row >= 0 && col >= 0)
	{
		if (!(fdf = (t_fdf *)malloc(sizeof(t_fdf))))
			fdf_exit(MALLOC_ERR);
		fdf->map_row = row;
		fdf->map_col = col;
		if (!(fdf->map = ft_intnew((size_t)fdf->map_row, (size_t)fdf->map_col)))
		{
			free(fdf);
			fdf_exit(MALLOC_ERR);
		}
	}
	else
		fdf_exit(EMPTY);
	return (fdf);
}

t_fdf	*orc(char **argv)
{
	t_fdf	*wireframe;
	int		cnt;
	int		fd;
	char	*line;

	cnt = 0;
	((fd = open(argv[1], O_RDONLY)) < 0) ? fdf_exit(CLOSE_ERR) : fd;
	wireframe = setup(argv[1]);
	while (get_next_line(fd, &line) == 1)
	{
		map_store(line, wireframe, cnt);
		cnt++;
		free(line);
	}
	if (close(fd) == -1)
	{
		arr_free((void **)wireframe->map, (size_t)wireframe->map_row, 1);
		free(wireframe);
		fdf_exit(CLOSE_ERR);
	}
	return (wireframe);
}
