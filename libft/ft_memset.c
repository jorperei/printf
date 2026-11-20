/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:50:14 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/06 16:16:11 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	j;

	j = (unsigned char)c;
	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = j;
		i++;
	}
	return (s);
}
/*this function fills the first 'n' bytes of 
the memory area pointed to by 's' with the byte 'c'*/
