/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:42:21 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 14:02:43 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_putnb(int n)
{
	char	i;
	int		s;
	
	s = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		s = 1;
	}
	if (n <= 9)
	{
		i = n + '0';
		return (write(1, &i, 1) + s);
	}
	else
		return (ft_putnb(n / 10) + ft_putnb(n % 10) + s);
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
