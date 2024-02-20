/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_separation_ff.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:22:06 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 19:38:20 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	lerp(float begin, t_line l);

int	ffdivider(int rrggbb, t_line l, float begin)
{
	int	rr;
	int	gg;
	int	bb;

	rr = rrggbb / 0x010000 % 0x0100;
	gg = rrggbb / 0x0100 % 0x0100;
	bb = rrggbb / 0x01 % 0x0100;
	rr = rr * lerp(begin, l);
	gg = gg * lerp(begin, l);
	bb = bb * lerp(begin, l);
	return (0x010000 * rr + 0x0100 * gg + 0x01 * bb);
}
