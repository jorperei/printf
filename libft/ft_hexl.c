/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:23:04 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/23 14:28:19 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexl(unsigned long n)
{
	char	*hexvalues;
	
	hexvalues = "0123456789abcdef";
	if (n >= 16)
		return (ft_hexl(n / 16) + ft_hexl(n % 16));
	else
		return (write(1, &hexvalues[n], 1));
}