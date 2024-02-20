/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:44:52 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 20:12:56 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define ANGLE 0.2

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
	int		**colors;
	int		mapcolors;
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
	int		xind;
	int		yind;
	int		x1ind;
	int		y1ind;
	int		xused;
}	t_line;
typedef struct s_step
{
	float	x;
	float	y;
	float	z;
}	t_step;
typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

#endif
