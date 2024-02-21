/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:15:50 by akozin            #+#    #+#             */
/*   Updated: 2024/02/21 12:29:23 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	super_free(char ***templine);
int		calc_width(char *filename, t_data *data);
int		calc_height(char *filename, t_data *data);
int		ft_ax(char *str, t_data *data);

void	free_exit(int code, t_data *data)
{
	if (data->matrix)
		free(data->matrix);
	if (data->colors)
		free(data->colors);
	exit(code);
}

void	data_colors_malloc(t_data *data, int j)
{
	data->colors[j] = (int *)malloc(sizeof (int) * data->width);
	if (!data->colors[j])
		free_exit(1, data);
}

void	line_atoi(char **templine, t_data *data, int j)
{
	int	i;

	i = 0;
	data_colors_malloc(data, j);
	while (i < data->width)
	{
		data->matrix[j][i] = ft_atoi(templine[i]);
		if (data->matrix[j][i] > data->max)
			data->max = data->matrix[j][i];
		if (ft_strchr(templine[i], ','))
		{
			if (!data->mapcolors)
				data->mapcolors = 1;
			data->colors[j][i] = ft_ax(ft_strchr(templine[i], ',') + 1, data);
		}
		else
			data->colors[j][i] = 0xffffff;
		i++;
	}
}

void	yet_another_data_init(t_data *data, char *filename)
{
	data->height = calc_height(filename, data);
	data->width = calc_width(filename, data);
	data->matrix = (int **)malloc(data->height * sizeof (int *));
	if (data->matrix == NULL)
		exit(1);
	data->colors = (int **)malloc(data->height * sizeof (int *));
	if (data->colors == NULL)
		free_exit(1, data);
}

void	read_map(char *filename, t_data *data)
{
	int		j;
	int		fd;
	char	**templine;
	char	*gnltemp;

	yet_another_data_init(data, filename);
	j = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		free_exit(1, data);
	while (j < data->height)
	{
		data->matrix[j] = (int *)malloc((data->width) * sizeof (int));
		if (data->matrix[j] == NULL)
		{
			close(fd);
			free_exit(1, data);
		}
		gnltemp = get_next_line(fd);
		templine = ft_split(gnltemp, ' ');
		line_atoi(templine, data, j++);
		super_free(&templine);
		free(gnltemp);
	}
	close(fd);
}
