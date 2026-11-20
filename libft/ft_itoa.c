/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 18:15:50 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:31:29 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(int num)
{
	int		temp;
	size_t	i;

	i = 0;
	temp = num;
	while (temp != 0)
	{
		temp = temp / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	size_t	j;
	size_t	i;

	j = 0;
	if (n <= 0)
		j = 1;
	c = malloc(ft_counter(n) + j + 1);
	if (!c)
		return (NULL);
	if (j == 1 && n != 0)
		c[0] = '-';
	if (n > 0)
		n = -n;
	i = ft_counter(n) + j;
	c[i--] = '\0';
	if (n == 0)
		c[i] = '0';
	while (n < 0)
	{
		c[i--] = -(n % 10) + '0';
		n = n / 10;
	}
	return (c);
}
/*
int	main(void)
{
	int	teste = -4562976;
	printf("%s\n", ft_itoa(teste));
	return (0);
}*/