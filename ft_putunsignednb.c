/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignednb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:09:30 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 17:33:46 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignednb(unsigned int n)
{
	char	i;

	if (n <= 9)
	{
		i = n + '0';
		return (write(1, &i, 1));
	}
	else
		return (ft_putunsignednb(n / 10) + ft_putunsignednb(n % 10));
}
