/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:30:35 by akozin            #+#    #+#             */
/*   Updated: 2024/02/19 15:47:27 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "fdf.h"

void	iterative_drawer(t_data *data, t_img *img);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

void	cleanser(t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < 1080)
	{
		x = 0;
		while (x < 1920)
		{
			my_mlx_pixel_put(img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	image_redraw(t_data *data, t_img *img)
{
	cleanser(img);
	iterative_drawer(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}
