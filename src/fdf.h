/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:44:52 by akozin            #+#    #+#             */
/*   Updated: 2024/02/19 15:42:39 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ANGLE 0.5

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct s_data
{
	int		height;
	int		width;
	int		**matrix;
	int		max;
	void	*mlx;
	void	*win;
	float	vs;
	float	gscale;
	int		xshift;
	int		yshift;
	t_img	img;
}	t_data;
typedef struct s_line
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
}	t_line;

#endif
