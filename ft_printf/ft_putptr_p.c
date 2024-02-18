/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:11:53 by akozin            #+#    #+#             */
/*   Updated: 2024/01/19 17:00:40 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_p(void *p)
{
	int	ret;

	ret = ft_putstr_p("0x");
	ret += ft_putlhex_p((unsigned long long int)p, 0);
	return (ret);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	void *asd;
	int rasd;
	char *qwe;
	int rqwe;
	int *zxc;
	int rzxc;

	asd = malloc(1);
	qwe = malloc(3);
	zxc = malloc(7);
	rasd = ft_putptr_p(asd);
	printf("\n%p\n%d\n", asd, rasd);
	rqwe = ft_putptr_p(qwe);
	printf("\n%p\n%d\n", qwe, rqwe);
	rzxc = ft_putptr_p(zxc);
	printf("\n%p\n%d\n", zxc, rzxc);
	return (0);
}
*/
