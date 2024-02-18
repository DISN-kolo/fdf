/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:01:15 by akozin            #+#    #+#             */
/*   Updated: 2024/01/20 16:06:43 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar_p(char c);
int	ft_putstr_p(char *s);
int	ft_putunbr_p(unsigned int n);
int	ft_putnbr_p(int n);
int	ft_putptr_p(void *p);
int	ft_putlhex_p(unsigned long long int n, int up);
int	ft_puthex_p(unsigned int n, int up);
int	ft_printf(const char *s, ...);

#endif
