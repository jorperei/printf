/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 17:27:16 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/24 16:32:22 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pstring(char *s)
{
	int	i;
	int	writevalue;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
	{
		writevalue = write(1, &s[i], 1);
		if (writevalue < 0)
			return (writevalue);
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	printf("%d\n", ft_pstring("sushi"));
}*/