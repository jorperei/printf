/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:02:33 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/24 16:30:43 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pptr(void *ptr)
{
	unsigned long	addr;
	int				valuecheck;
	int				writevalue;

	if (ptr == NULL)
	{
		return (write(1, "(nil)", 5));
	}
	addr = (unsigned long)ptr;
	writevalue = write(1, "0x", 2);
	if (writevalue < 0)
		return (writevalue);
	valuecheck = ft_hexl(addr);
	if (valuecheck < 0)
		return (valuecheck);
	return (2 + valuecheck);
}

/*
#include <limits.h>

int	ft_pptr(void *ptr);

static void	test(void *p)
{
	int	r1;
	int	r2;

	printf("real: ");
	r1 = printf("%p", p);
	printf("  (ret %d)\n", r1);
	printf("mine: ");
	r2 = ft_pptr(p);
	printf("  (ret %d)\n\n", r2);
}

int	main(void)
{
	int		x;
	void	*h;

	setbuf(stdout, NULL);
	x = 42;
	h = malloc(1);
	test(&x);
	test(h);
	test(NULL);
	test((void *)1);
	test((void *)255);
	test((void *)ULONG_MAX);
	free(h);
	return (0);
}*/