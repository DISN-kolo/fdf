/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:13:03 by akozin            #+#    #+#             */
/*   Updated: 2024/02/10 17:10:49 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx/mlx.h"
#include <math.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel/8));
	*(unsigned int *)dst = color;
}

/*
double	dabs(double i)
{
	return (i * (i > 0));
}
*/
int	circle_pixel_calc(int x, int y, double delta, double radius)
{
	return ((sqrt(pow(x - 1920.f/2, 2.f) + pow(y - 1080.f/2, 2.f)) -
				radius <= delta) && (sqrt(pow(x - 1920.f/2, 2.f) + pow(y -
				1080.f/2, 2.f)) - radius >= -delta));
}

int	ffgrad(int x, const int full)
{
	return ((int)(0xFF/(double)full*x));
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "sup people");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	for (int i = 0; i < 1920; i++)
		for (int j = 0; j < 1080; j++)
			{
				my_mlx_pixel_put(&img, i, j,
						0x000000FF * circle_pixel_calc(i, j, 9, 200) +
						0x00010000 * ffgrad(i, 1920) +
						0x00000100 * ffgrad(j, 1080));
			}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
