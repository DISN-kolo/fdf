/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:04:17 by akozin            #+#    #+#             */
/*   Updated: 2024/01/20 12:30:19 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_nbrlen(unsigned int x)
{
	int	count;

	count = 0;
	if (!x)
		return (1);
	while (x)
	{
		x /= 10;
		count++;
	}
	return (count);
}

/* c = current, w = letter ("w" for "word" because i'm stoopid
 */
int	ft_putunbr_p(unsigned int n)
{
	unsigned long int	c;
	char				w;
	int					nlen;

	nlen = ft_nbrlen(n);
	c = (unsigned long int)n;
	if (c >= 10)
		ft_putunbr_p(c / 10);
	w = c % 10 + '0';
	write(1, &w, 1);
	return (nlen);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int	placeme;
	placeme = ft_putunbr_p(atoi(argv[1]));
	printf("\n%d\n", atoi(argv[1]));
	printf("nlen was: %d\n", placeme);
	return (0);
}
*/
