/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:13:03 by akozin            #+#    #+#             */
/*   Updated: 2024/02/19 19:36:48 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "fdf.h"
#include "../mlx/mlx.h"
#include <math.h>
#include <stdlib.h>

void	read_map(char *filename, t_data *data);
void	keycode_handler(int keycode, t_data *data);
void	image_redraw(t_data *data, t_img *img);
int		fname_check(char *filename);

int	nclose(t_data *data)
{
	int	y;

	mlx_destroy_window(data->mlx, data->win);
	y = 0;
	while (y < data->height)
		free(data->matrix[y++]);
	free(data->matrix);
	free(data->mlx);
	exit(0);
}

// i think it's ironic a "close" function is also used to handle keycodes
// and not just close the window -- just like the kill command in the shell
// is actually used to send signals, not just kill
int	mclose(int keycode, t_data *data)
{
	int	y;

	y = 0;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		while (y < data->height)
			free(data->matrix[y++]);
		free(data->matrix);
		free(data->mlx);
		exit(0);
	}
	keycode_handler(keycode, data);
	return (0);
}

void	data_init(t_data *data)
{
	data->vs = 1.2f;
	data->max = 0;
}

void	data_init2(t_data *data)
{
	data->gscale = 1080 / ((data->width + data->height) * cos(ANGLE));
	data->xshift = 1920 / 2;
	data->yshift = 1080 / 2 - 200;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FDF42");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	if (!fname_check(argv[1]))
	{
		ft_printf("File must exist and its name must end in .fdf\n");
		return (1);
	}
	data_init(&data);
	read_map(argv[1], &data);
	data_init2(&data);
	mlx_hook(data.win, 2, 0, mclose, &data);
	mlx_hook(data.win, 17, 0, nclose, &data);
	data.img.img = mlx_new_image(data.mlx, 1920, 1080);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel,
			&data.img.line_length, &data.img.endian);
	image_redraw(&data, &data.img);
	mlx_loop(data.mlx);
	free(data.matrix);
	return (0);
}
