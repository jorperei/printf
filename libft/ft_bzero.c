/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:51:17 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/10 13:38:49 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*m;

	m = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		m[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char	test[6] = "sushi";
	int		i;

	ft_bzero(test, 3);
	i = 0;
	while (i < 6)
	{
		printf("%02x\n", (unsigned char)test[i]);
        printf("%c\n", (unsigned char)test[i]);
		i++;
	}
}*/