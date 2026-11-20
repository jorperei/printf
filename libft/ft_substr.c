/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:27:26 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/10 13:26:19 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	strt;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	strt = (size_t)start;
	sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (s[strt] && i < len)
	{
		sub[i] = s[strt];
		i++;
		strt++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char const *teste = "sushi";
	unsigned int starttest = 10;
	size_t		lenteste = 2;
	char *t = ft_substr(teste, starttest, lenteste);
	printf("%s\n", t);
	free (t);
	return (0);
}*/