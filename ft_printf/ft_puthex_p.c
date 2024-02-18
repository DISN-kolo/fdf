/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akozin <akozin@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:04:17 by akozin            #+#    #+#             */
/*   Updated: 2024/01/20 16:07:31 by akozin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_nbrxlen(unsigned int x)
{
	int	count;

	count = 0;
	if (!x)
		return (1);
	while (x)
	{
		x /= 16;
		count++;
	}
	return (count);
}

/* c = current, w = letter ("w" for "word" because i'm stoopid
 */
int	ft_puthex_p(unsigned int n, int up)
{
	char		w;
	int			nlen;

	nlen = ft_nbrxlen(n);
	if (n >= 16)
		ft_puthex_p(n / 16, up);
	if (up)
		w = "0123456789ABCDEF"[n % 16];
	else
		w = "0123456789abcdef"[n % 16];
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
	placeme = ft_putlhex_p(strtol(argv[1], 0, 10), 0);
	printf("\n");
	placeme = ft_putlhex_p(strtol(argv[1], 0, 10), 1);
	printf("\n%lx\n", strtol(argv[1], 0, 10));
	printf("%lX\n", strtol(argv[1], 0, 10));
	printf("nlen was: %d\n", placeme);
	return (0);
}
*/
