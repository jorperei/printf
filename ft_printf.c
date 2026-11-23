/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:20:16 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 18:35:52 by jorperei         ###   ########.fr       */
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

int	ft_printf(const char *tp, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, tp);
	while (tp[i])
	{
		if (tp[i] == '%' && tp[i + 1] != '\0')
		{
			count += ft_sort(tp[i + 1], &args);
			i += 2;
		}
		else
		{
			write(1, &tp[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
