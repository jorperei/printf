/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 16:32:31 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/12 17:35:33 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;

	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, ft_strlen(s1) + 1);
	ft_strlcat(c, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (c);
}
/*
int	main(void)
{
	char const	*t1 = "eu gosto de ";
	char const	*t2 = "sushi";

	printf("%s\n", ft_strjoin(t1, t2));
	return (0);
}*/