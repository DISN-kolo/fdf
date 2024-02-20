/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:39:54 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 15:23:41 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "fdf.h"

int		wc(const char *s, char c);
void	free_exit(int code, t_data *data);

// this file is mostly for read_map.c
void	super_free(char ***templine)
{
	int	i;

	i = 0;
	while ((*templine)[i])
		free((*templine)[i++]);
	free((*templine));
}

int	calc_width(char *filename, t_data *data)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		free_exit(1, data);
	line = get_next_line(fd);
	if (line)
		ret = wc(line, ' ');
	else
	{
		close(fd);
		free_exit(1, data);
	}
	while (line)
	{
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (ret);
}

int	calc_height(char *filename, t_data *data)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		free_exit(1, data);
	line = get_next_line(fd);
	while (line)
	{
		if (line)
			free(line);
		lines++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (lines);
}

// this checks the fname to be in *.fdf format
int	fname_check(char *filename)
{
	char	*testline;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	testline = ft_strrchr(filename, '.');
	if (!testline)
		return (0);
	if (!ft_strncmp(testline, ".fdf", 5))
		return (1);
	return (0);
}
