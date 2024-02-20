/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 17:45:17 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 17:03:31 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../mlx/mlx.h"

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

int	fflerp(t_data *data, t_line l, int start, int stop)
{
	float	delta;

	delta = data->matrix[l.y1ind][l.x1ind] - data->matrix[l.yind][l.xind];
	if (delta < 0.000001 && delta > -0.000001)
		return (stop);
	return ((int)((l.z1 - l.z) / delta * (start - stop) + stop));
}

void	bresenham(t_line l, t_img *img, t_data *data)
{
	float	step_x;
	float	step_y;
	float	step_z;
	float	max_abs;

	if (abs_float(l.x - l.x1) > abs_float(l.y - l.y1))
		max_abs = abs_float(l.x - l.x1);
	else
		max_abs = abs_float(l.y - l.y1);
	step_y = (l.y1 - l.y) / max_abs;
	step_x = (l.x1 - l.x) / max_abs;
	step_z = (l.z1 - l.z) / max_abs;
	while ((int)(l.x - l.x1) || (int)(l.y - l.y1))
	{
		if (!data->mapcolors)
			my_mlx_pixel_put(img, l.x, l.y, ffgrad(l.z, data->max) / 4
				* 0x00020301 + 0x007f0000);
		else
			my_mlx_pixel_put(img, l.x, l.y, fflerp(data, l,
				data->colors[l.yind][l.xind], data->colors[l.y1ind][l.x1ind]));
		l.z += step_z;
		l.x += step_x;
		l.y += step_y;
	}
}
