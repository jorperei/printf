/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:23:17 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/24 18:20:44 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexu(unsigned long n)
{
	char	*hexvalues;
	int		writevalue1;
	int		writevalue2;

	hexvalues = "0123456789ABCDEF";
	if (n >= 16)
	{
		writevalue1 = ft_hexu(n / 16);
		if (writevalue1 < 0)
			return (writevalue1);
		writevalue2 = ft_hexu(n % 16);
		if (writevalue2 < 0)
			return (writevalue2);
		writevalue1 += writevalue2;
	}
	else
		writevalue1 = write(1, &hexvalues[n], 1);
	return (writevalue1);
}
