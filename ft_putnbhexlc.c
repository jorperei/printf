/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbhexlc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:16:09 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 17:33:39 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbhexlc(unsigned int n)
{
	return (ft_hexl(n));
}

/*
#include <limits.h>

int	ft_putnbhexlc(unsigned int n);

static void	test(unsigned int n)
{
	int	r1;
	int	r2;

	printf("real: ");
	r1 = printf("%x", n);
	printf("  (ret %d)\n", r1);
	printf("mine: ");
	r2 = ft_putnbhexlc(n);
	printf("  (ret %d)\n\n", r2);
}

int	main(void)
{
	setbuf(stdout, NULL);
	test(0);
	test(9);
	test(10);
	test(15);
	test(16);
	test(255);
	test(4096);
	test(123456789);
	test(INT_MAX);
	test(UINT_MAX);
	test(-1);
	return (0);
}*/