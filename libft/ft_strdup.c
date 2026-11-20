/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:01:51 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/10 13:16:29 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*sub;

	len = ft_strlen(s) + 1;
	i = 0;
	sub = malloc(sizeof(char) * len);
	if (!sub)
		return (NULL);
	while (s[i])
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
int	main(void)
{
	const char *test = "";
	char *copy = ft_strdup(test);
	printf("%s\n", copy);
	free (copy);
	return (0);
}*/