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
		return (1 - (l.x1 - l.x) / (l.x1 - begin));
	else
		return (1 - (l.y1 - l.y) / (l.y1 - begin));
}


int	ffdivider(int rrggbb, t_line l, float begin)
{
	int	sgn;
	int	rr;
	int	gg;
	int	bb;

	sgn = 2*(rrggbb >= 0) - 1;
	rrggbb *= sgn;
	rr = rrggbb / 0x010000;
	gg = rrggbb / 0x0100 % 0x0100;
	bb = rrggbb % 0x0100;
	rr = rr * lerp(begin, l);
	gg = gg * lerp(begin, l);
	bb = bb * lerp(begin, l);
	return (sgn*(0x010000 * rr + 0x0100 * gg + 0x01 * bb));
}
