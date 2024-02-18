/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:05:25 by akozin            #+#    #+#             */
/*   Updated: 2024/01/20 12:42:58 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_p(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (ft_putstr_p("(null)"));
	while (*s)
		l += ft_putchar_p(*s++);
	return (l);
}
