/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:20:16 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/25 16:09:52 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_sort(char c, va_list *args)
{
	if (c == 'c')
		return (ft_sc(va_arg(*args, int)));
	if (c == 's')
		return (ft_pstring(va_arg(*args, char *)));
	if (c == 'p')
		return (ft_pptr(va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnb(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putunsignednb(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_putnbhexlc(va_arg(*args, unsigned int)));
	if (c == 'X')
		return (ft_putnbhexuc(va_arg(*args, unsigned int)));
	if (c == '%')
		return (ft_sc('%'));
	return (0);
}

static int	ft_step(const char *tp, int *i, va_list *args)
{
	int	ret;

	if (tp[*i] == '%' && tp[*i + 1] != '\0')
	{
		ret = ft_sort(tp[*i + 1], args);
		*i += 2;
		return (ret);
	}
	else
	{
		ret = write(1, &tp[*i], 1);
		*i += 1;
		return (ret);
	}
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	int		temp;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		temp = ft_step(format, &i, &args);
		if (temp < 0)
		{
			va_end(args);
			return (-1);
		}
		else
			count += temp;
	}
	va_end(args);
	return (count);
}
/*

int	main(void)
{
	int		a;
	int		b;
	int		x;
	char	*nul;

	x = 42;
	nul = NULL;
	setbuf(stdout, NULL);

	a = printf("hello"); printf(" <- real %d\n", a);
	b = ft_printf("hello"); printf(" <- mine %d\n\n", b);

	a = printf("%c", 'a'); printf(" <- real %d\n", a);
	b = ft_printf("%c", 'a'); printf(" <- mine %d\n\n", b);

	a = printf("%c%c%c", 'a', 'b', 'c'); printf(" <- real %d\n", a);
	b = ft_printf("%c%c%c", 'a', 'b', 'c'); printf(" <- mine %d\n\n", b);

	a = printf("a%cb", 0); printf(" <- real %d\n", a);
	b = ft_printf("a%cb", 0); printf(" <- mine %d\n\n", b);

	a = printf("%s", "sushi"); printf(" <- real %d\n", a);
	b = ft_printf("%s", "sushi"); printf(" <- mine %d\n\n", b);

	a = printf("%s", ""); printf(" <- real %d\n", a);
	b = ft_printf("%s", ""); printf(" <- mine %d\n\n", b);

	a = printf("%s", nul); printf(" <- real %d\n", a);
	b = ft_printf("%s", nul); printf(" <- mine %d\n\n", b);

	a = printf("%s", "%d %s"); printf(" <- real %d\n", a);
	b = ft_printf("%s", "%d %s"); printf(" <- mine %d\n\n", b);

	a = printf("%p", &x); printf(" <- real %d\n", a);
	b = ft_printf("%p", &x); printf(" <- mine %d\n\n", b);

	a = printf("%p", nul); printf(" <- real %d\n", a);
	b = ft_printf("%p", nul); printf(" <- mine %d\n\n", b);

	a = printf("%p", (void *)1); printf(" <- real %d\n", a);
	b = ft_printf("%p", (void *)1); printf(" <- mine %d\n\n", b);

	a = printf("%p", (void *)255); printf(" <- real %d\n", a);
	b = ft_printf("%p", (void *)255); printf(" <- mine %d\n\n", b);

	a = printf("%p", (void *)ULONG_MAX); printf(" <- real %d\n", a);
	b = ft_printf("%p", (void *)ULONG_MAX); printf(" <- mine %d\n\n", b);

	a = printf("%d", 0); printf(" <- real %d\n", a);
	b = ft_printf("%d", 0); printf(" <- mine %d\n\n", b);

	a = printf("%d", -5); printf(" <- real %d\n", a);
	b = ft_printf("%d", -5); printf(" <- mine %d\n\n", b);

	a = printf("%d", 10); printf(" <- real %d\n", a);
	b = ft_printf("%d", 10); printf(" <- mine %d\n\n", b);

	a = printf("%d", -42); printf(" <- real %d\n", a);
	b = ft_printf("%d", -42); printf(" <- mine %d\n\n", b);

	a = printf("%d", INT_MAX); printf(" <- real %d\n", a);
	b = ft_printf("%d", INT_MAX); printf(" <- mine %d\n\n", b);

	a = printf("%d", INT_MIN); printf(" <- real %d\n", a);
	b = ft_printf("%d", INT_MIN); printf(" <- mine %d\n\n", b);

	a = printf("%i", -7); printf(" <- real %d\n", a);
	b = ft_printf("%i", -7); printf(" <- mine %d\n\n", b);

	a = printf("%u", 0); printf(" <- real %d\n", a);
	b = ft_printf("%u", 0); printf(" <- mine %d\n\n", b);

	a = printf("%u", 42); printf(" <- real %d\n", a);
	b = ft_printf("%u", 42); printf(" <- mine %d\n\n", b);

	a = printf("%u", UINT_MAX); printf(" <- real %d\n", a);
	b = ft_printf("%u", UINT_MAX); printf(" <- mine %d\n\n", b);

	a = printf("%u", -1); printf(" <- real %d\n", a);
	b = ft_printf("%u", -1); printf(" <- mine %d\n\n", b);

	a = printf("%x", 0); printf(" <- real %d\n", a);
	b = ft_printf("%x", 0); printf(" <- mine %d\n\n", b);

	a = printf("%x", 255); printf(" <- real %d\n", a);
	b = ft_printf("%x", 255); printf(" <- mine %d\n\n", b);

	a = printf("%x", 4096); printf(" <- real %d\n", a);
	b = ft_printf("%x", 4096); printf(" <- mine %d\n\n", b);

	a = printf("%x", -1); printf(" <- real %d\n", a);
	b = ft_printf("%x", -1); printf(" <- mine %d\n\n", b);

	a = printf("%X", 255); printf(" <- real %d\n", a);
	b = ft_printf("%X", 255); printf(" <- mine %d\n\n", b);

	a = printf("%X", 0xabcdef); printf(" <- real %d\n", a);
	b = ft_printf("%X", 0xabcdef); printf(" <- mine %d\n\n", b);

	a = printf("%X", -1); printf(" <- real %d\n", a);
	b = ft_printf("%X", -1); printf(" <- mine %d\n\n", b);

	a = printf("%%"); printf(" <- real %d\n", a);
	b = ft_printf("%%"); printf(" <- mine %d\n\n", b);

	a = printf("100%%"); printf(" <- real %d\n", a);
	b = ft_printf("100%%"); printf(" <- mine %d\n\n", b);

	a = printf("%%%%"); printf(" <- real %d\n", a);
	b = ft_printf("%%%%"); printf(" <- mine %d\n\n", b);

	a = printf("%d%%", 50); printf(" <- real %d\n", a);
	b = ft_printf("%d%%", 50); printf(" <- mine %d\n\n", b);

	a = printf("%%d"); printf(" <- real %d\n", a);
	b = ft_printf("%%d"); printf(" <- mine %d\n\n", b);

	a = printf("%d %s %x %X %c %% %u", 42, "sushi", 255, 255, 'z', 7u);
	printf(" <- real %d\n", a);
	b = ft_printf("%d %s %x %X %c %% %u", 42, "sushi", 255, 255, 'z', 7u);
	printf(" <- mine %d\n\n", b);

	a = printf("%s %d %s %d", "a", 1, "b", 2); printf(" <- real %d\n", a);
	b = ft_printf("%s %d %s %d", "a", 1, "b", 2); printf(" <- mine %d\n\n", b);

	a = printf("%c%s%d%x%X%u%p%%", 'a', "b", 3, 4, 5, 6u, &x);
	printf(" <- real %d\n", a);
	b = ft_printf("%c%s%d%x%X%u%p%%", 'a', "b", 3, 4, 5, 6u, &x);
	printf(" <- mine %d\n\n", b);

	return (0);
}*/
