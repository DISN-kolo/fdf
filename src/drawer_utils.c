/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:54:03 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 19:18:12 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	abs_float(float i);

float	step_setter(t_line l, float *max_abs, t_step *step)
{
	float	begin;

	if (abs_float(l.x - l.x1) > abs_float(l.y - l.y1))
	{
		*max_abs = abs_float(l.x - l.x1);
		begin = l.x;
	}
	else
	{
		*max_abs = abs_float(l.y - l.y1);
		begin = l.y;
	}
	step->y = (l.y1 - l.y) / *max_abs;
	step->x = (l.x1 - l.x) / *max_abs;
	step->z = (l.z1 - l.z) / *max_abs;
	return (begin);
}

void	l_increase(t_line *l, t_step step)
{
	l->z += step.z;
	l->x += step.x;
	l->y += step.y;
}
