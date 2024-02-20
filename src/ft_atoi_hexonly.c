/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexonly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:07:12 by akozin            #+#    #+#             */
/*   Updated: 2024/02/20 19:46:31 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_exit(int code, t_data *data);

int	ft_ax(char *str, t_data *data)
{
	int	res;

	str += 2;
	res = 0;
	while (*str && *str != '\n')
	{
		res *= 16;
		if (*str >= 'a' && *str <= 'f')
			res += *str - 'a' + 10;
		if (*str >= 'A' && *str <= 'F')
			res += *str - 'A' + 10;
		else if (*str >= '0' && *str <= '9')
			res += *str - '0';
		else
			free_exit(1, data);
		str++;
	}
	return (res);
}
