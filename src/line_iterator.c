/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_iterator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:18:56 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 16:51:31 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	bresenham(t_line l, t_img *img, t_data *data);

static void	l_shifter(t_line *ret, t_data *data)
{
	ret->x *= data->gscale;
	ret->y *= data->gscale;
	ret->x1 *= data->gscale;
	ret->y1 *= data->gscale;
	ret->x += data->xshift;
	ret->y += data->yshift;
	ret->x1 += data->xshift;
	ret->y1 += data->yshift;
}

/* if it's not right, it's down */
static t_line	l_filler(t_data *data, int x, int y, int right)
{
	t_line	ret;

	if (right)
	{
		ret.x = (x - y) * cos(ANGLE);
		ret.y = (x + y) * sin(ANGLE) - data->matrix[y][x] * data->vs;
		ret.x1 = (x + 1 - y) * cos(ANGLE);
		ret.y1 = (x + 1 + y) * sin(ANGLE) - data->matrix[y][x + 1] * data->vs;
		ret.x1ind = x + 1;
		ret.y1ind = y;
	}
	else
	{
		ret.x = (x - y) * cos(ANGLE);
		ret.y = (x + y) * sin(ANGLE) - data->matrix[y][x] * data->vs;
		ret.x1 = (x - y - 1) * cos(ANGLE);
		ret.y1 = (x + y + 1) * sin(ANGLE) - data->matrix[y + 1][x] * data->vs;
		ret.x1ind = x;
		ret.y1ind = y + 1;
	}
	l_shifter(&ret, data);
	ret.xind = x;
	ret.yind = y;
	return (ret);
}

static void	iterative_logic(t_data *data, t_img *img, int xind, int yind)
{
	t_line	line;

	if (xind != data->width - 1)
	{
		line = l_filler(data, xind, yind, 1);
		line.z = data->matrix[yind][xind];
		line.z1 = data->matrix[yind][xind + 1];
		bresenham(line, img, data);
	}
	if (yind != data->height - 1)
	{
		line = l_filler(data, xind, yind, 0);
		line.z = data->matrix[yind][xind];
		line.z1 = data->matrix[yind + 1][xind];
		bresenham(line, img, data);
	}
}

void	iterative_drawer(t_data *data, t_img *img)
{
	int		xind;
	int		yind;

	yind = 0;
	while (yind < data->height)
	{
		xind = 0;
		while (xind < data->width)
		{
			iterative_logic(data, img, xind, yind);
			xind++;
		}
		yind++;
	}
}
