/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:58:56 by akozin            #+#    #+#             */
/*   Updated: 2024/01/20 16:06:53 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_substit(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar_p(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr_p(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr_p(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_p(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_putunbr_p(va_arg(ap, unsigned int)));
	else if (c == 'x')
		return (ft_puthex_p(va_arg(ap, unsigned long long int), 0));
	else if (c == 'X')
		return (ft_puthex_p(va_arg(ap, unsigned long long int), 1));
	else if (c == '%')
		return (ft_putchar_p('%'));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		ret;
	int		temp;

	ret = 0;
	i = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			temp = ft_substit(ap, s[i]);
			if (temp == -1)
				return (-1);
			else
				ret += temp;
		}
		else
			ret += ft_putchar_p(s[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}
