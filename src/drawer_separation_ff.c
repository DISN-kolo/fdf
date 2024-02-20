/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_separation_ff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:22:06 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 20:17:39 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	abs_float(float i);

float	lerp(float begin, t_line l)
{
	if (l.x1 == begin || l.y1 == begin)
		return (0);
	if (l.xused)
		return ((l.x1 - l.x) / (l.x1 - begin));
	else
		return ((l.y1 - l.y) / (l.y1 - begin));
}

t_rgb	int_to_rgb(int i)
{
	t_rgb	col;

	col.r = i / 0x010000;
	col.g = i / 0x0100 % 0x0100;
	col.b = i % 0x0100;
	return (col);
}

int	rgb_to_int(t_rgb col)
{
	return (col.r * 0x010000 + col.g * 0x0100 + col.b * 0x01);
}

int	ffdivider(t_data *data, t_line l, float begin)
{
	t_rgb	oc;
	t_rgb	nc;
	t_rgb	rc;

	oc = int_to_rgb(data->colors[l.yind][l.xind]);
	nc = int_to_rgb(data->colors[l.y1ind][l.x1ind]);
	oc.r *= lerp(begin, l);
	oc.g *= lerp(begin, l);
	oc.b *= lerp(begin, l);
	nc.r *= 1 - lerp(begin, l);
	nc.g *= 1 - lerp(begin, l);
	nc.b *= 1 - lerp(begin, l);
	rc.r = oc.r + nc.r;
	rc.g = oc.g + nc.g;
	rc.b = oc.b + nc.b;
	return (rgb_to_int(rc));
}
