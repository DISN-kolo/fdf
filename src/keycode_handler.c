/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:02:13 by akozin            #+#    #+#             */
/*   Updated: 2024/06/05 15:20:59 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_redraw(t_data *data, t_img *img);

//  0 = zoom
//  1 = pan
// -1 = wrong :)
/* upp keycode is 65362
down keycode is 65364
left keycode is 65361
right keycode is 65363
*/
int	keycode_type(int keycode)
{
	if (keycode == 113 || keycode == 119 || keycode == 97 || keycode == 115)
		return (0);
	if (keycode == 65362 || keycode == 65364
		|| keycode == 65361 || keycode == 65363)
		return (1);
	return (-1);
}

void	handle_zoom(int keycode, t_data *data)
{
	if (keycode == 113)
		data->vs += 0.02f;
	if (keycode == 119)
		data->vs -= 0.02f;
	if (keycode == 97)
		data->gscale += 2.f;
	if (keycode == 115)
	{
		data->gscale -= 2.f;
		if (data->gscale < 2)
			data->gscale = 2.f;
	}
}

void	handle_pan(int keycode, t_data *data)
{
	if (keycode == 65363)
		data->xshift -= 100;
	if (keycode == 65361)
		data->xshift += 100;
	if (keycode == 65362)
		data->yshift += 100;
	if (keycode == 65364)
		data->yshift -= 100;
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
