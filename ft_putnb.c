/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:42:21 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/24 17:45:47 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_failcheck(int a, int b)
{
	if (a < 0 || b < 0)
		return (-1);
	return (a + b);
}

int	ft_putnb(int n)
{
	char	i;
	int		s;
	int		r;

	s = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		s = write(1, "-", 1);
		if (s < 0)
			return (-1);
		n = n * -1;
	}
	if (n <= 9)
	{
		i = n + '0';
		return (ft_failcheck(write(1, &i, 1), s));
	}
	r = ft_putnb(n / 10);
	return (ft_failcheck(ft_failcheck(r, ft_putnb(n % 10)), s));
}

/*
#include <limits.h>

int	ft_putnb(int n);

static void	test(int n)
{
	int	r1;
	int	r2;

	printf("real: ");
	r1 = printf("%d", n);
	printf("  (ret %d)\n", r1);
	printf("mine: ");
	r2 = ft_putnb(n);
	printf("  (ret %d)\n\n", r2);
}


int	main(void)
{
	setbuf(stdout, NULL);
	test(0);
	test(5);
	test(-5);
	test(9);
	test(10);
	test(42);
	test(-42);
	test(100);
	test(INT_MAX);
	test(INT_MIN);
	return (0);
}*/
