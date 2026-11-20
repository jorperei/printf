/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 17:45:29 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:30:45 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;
	char	*c;

	if (!s1 || s1[0] == '\0')
	{
		c = malloc(1);
		if (!c)
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	i = 0;
	k = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (k > i && ft_strchr(set, s1[k]))
		k--;
	c = malloc((k - i) + 2);
	if (!c)
		return (NULL);
	ft_strlcpy(c, &(s1[i]), (k - i) + 2);
	return (c);
}
/*
int	main(void)
{
	char const	*t1 = "";
	char const	*t2 = "";
	char		*c;

	c = ft_strtrim(t1, t2);
	printf("%s\n", c);
	free (c);
	return (0);
}*/