/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:02:13 by akozin            #+#    #+#             */
/*   Updated: 2024/02/19 16:19:35 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_redraw(t_data *data, t_img *img);

//  0 = zoom
//  1 = pan
// -1 = wrong :)
int	keycode_type(int keycode)
{
	if (keycode == 12 || keycode == 13 || keycode == 0 || keycode == 1)
		return (0);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		return (1);
	return (-1);
}

void	handle_zoom(int keycode, t_data *data)
{
	if (keycode == 12)
		data->vs += 0.02f;
	if (keycode == 13)
		data->vs -= 0.02f;
	if (keycode == 0)
		data->gscale += 2.f;
	if (keycode == 1)
	{
		data->gscale -= 2.f;
		if (data->gscale < 2)
			data->gscale = 2.f;
	}
}

void	handle_pan(int keycode, t_data *data)
{
	if (keycode == 123)
		data->xshift += 100;
	if (keycode == 124)
		data->xshift -= 100;
	if (keycode == 125)
		data->yshift -= 100;
	if (keycode == 126)
		data->yshift += 100;
}

void	keycode_handler(int keycode, t_data *data)
{
	if (keycode_type(keycode) == 0)
		handle_zoom(keycode, data);
	if (keycode_type(keycode) == 1)
		handle_pan(keycode, data);
	if (keycode_type(keycode) == -1)
		return ;
	image_redraw(data, &data->img);
}
