/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:45:17 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 20:54:03 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"
#include <stdio.h>

t_line	l_filler(t_data *data, int x, int y, int right);
float	step_setter(t_line *l, float *max_abs, t_step *step);
void	l_increase(t_line *l, t_step step);
int		ffdivider(int rrggbb, t_line l, float begin);

float	abs_float(float i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 1920 || y >= 1080 || x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ffgrad(float param, float max)
{
	if (max < 0.000001 && max > -0.000001)
		return (0xff);
	if (param / max < 0)
		return (0x00);
	return ((int)(0xff * param / max));
}

void	bresenham(t_line l, t_img *img, t_data *data)
{
	t_step	step;
	float	max_abs;
	float	begin;

	begin = step_setter(&l, &max_abs, &step);
	while ((int)(l.x - l.x1) || (int)(l.y - l.y1))
	{
		if (!data->mapcolors)
			my_mlx_pixel_put(img, l.x, l.y, ffgrad(l.z, data->max) / 4
				* 0x00020301 + 0x007f0000);
		else
			my_mlx_pixel_put(img, l.x, l.y,
					data->colors[l.yind][l.xind] + ffdivider(
						- data->colors[l.yind][l.xind]
						+ data->colors[l.y1ind][l.x1ind], l, begin));
		l_increase(&l, step);
	}
}
