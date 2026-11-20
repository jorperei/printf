/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 19:34:22 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/16 16:24:57 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;
	size_t			t;

	t = ft_strlen(s);
	i = 0;
	c = malloc(t + 1);
	if (!c)
		return (NULL);
	while (i < t)
	{
		c[i] = f(i, s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}

/*
static char	testfunction(unsigned int i, char c)
{
	if (i >= 2 && c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
int main(void)
{
    char    *teste = "sushi";
	char	*r;
	r = ft_strmapi(teste, testfunction);
	printf("%s\n", r);
	free (r);
	return (0);
}*/