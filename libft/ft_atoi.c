/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:41:27 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/12 17:38:52 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	char	*n;	
	int		j;
	int		r;

	j = 0;
	i = 0;
	r = 0;
	n = (char *)nptr;
	while ((n[i] >= 9 && n[i] <= 13) || n[i] == ' ')
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			j = 1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		r = r * 10 + (n[i] - '0');
		i++;
	}
	if (j == 1)
		r = r * -1;
	return (r);
}

/*
int main(void)
{
	const char *t = "    +432a&7";
	printf("%d\n", ft_atoi(t));
}*/