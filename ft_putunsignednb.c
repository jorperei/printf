/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:09:30 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/24 17:04:59 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednb(unsigned int n)
{
	char	i;
	int		writevalue1;
	int		writevalue2;

	if (n <= 9)
	{
		i = n + '0';
		return (write(1, &i, 1));
	}
	else
	{
		writevalue1 = ft_putunsignednb(n / 10);
		if (writevalue1 < 0)
			return (writevalue1);
		writevalue2 = ft_putunsignednb(n % 10);
		if (writevalue2 < 0)
			return (writevalue2);
		writevalue1 += writevalue2;
	}
	return (writevalue1);
}
