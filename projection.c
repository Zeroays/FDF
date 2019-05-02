/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <vrabaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 12:22:29 by vrabaib           #+#    #+#             */
/*   Updated: 2019/05/01 21:44:43 by vrabaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int x_tmp;
	int y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp + y_tmp) * cos(ISO_ANGLE);
	*y = -z + (x_tmp - y_tmp) * sin(ISO_ANGLE);
}

void	military(int *x, int *y, int z)
{
	int x_tmp;
	int y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp + y_tmp) * cos(MILITARY_ANGLE);
	*y = -z + (x_tmp - y_tmp) * sin(MILITARY_ANGLE);
}
