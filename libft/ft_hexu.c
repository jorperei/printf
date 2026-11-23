/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:23:17 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 14:28:12 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexu(unsigned long n)
{
	char	*hexvalues;
	
	hexvalues = "0123456789ABCDEF";
	if (n >= 16)
		return (ft_hexu(n / 16) + ft_hexu(n % 16));
	else
		return (write(1, &hexvalues[n], 1));
}