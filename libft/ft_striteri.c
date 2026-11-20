/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:49:28 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/16 16:24:43 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
static void	testfunction(unsigned int i, char *c)
{
	if (i >= 2 && *c >= 'a' && *c <= 'z')
		*c = *c - 32;
}
int main(void)
{
    char    teste[] = "";
	ft_striteri(teste, testfunction);
	printf("%s\n", teste);
	return (0);
}*/