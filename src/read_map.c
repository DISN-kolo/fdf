/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:15:50 by akozin            #+#    #+#             */
/*   Updated: 2024/02/19 18:06:03 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

void	super_free(char ***templine);
int		calc_width(char *filename);
int		calc_height(char *filename);

void	free_exit(int code, t_data *data)
{
	if (data->matrix)
		free(data->matrix);
	exit(code);
}

void	line_atoi(char **templine, t_data *data, int j)
{
	int	i;

	i = 0;
	while (i < data->width)
	{
		data->matrix[j][i] = ft_atoi(templine[i]);
		if (data->matrix[j][i] > data->max)
			data->max = data->matrix[j][i];
		i++;
	}
}

void	yet_another_data_init(t_data *data, char *filename)
{
	data->height = calc_height(filename);
	data->width = calc_width(filename);
	data->matrix = (int **)malloc((data->height + 1) * sizeof (int *));
	if (data->matrix == NULL)
		exit(1);
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
	while (j < data->height)
	{
		data->matrix[j] = (int *)malloc((data->width + 1) * sizeof (int));
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
