/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 17:05:16 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:28:58 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	while (i < size && dst[i])
		i++;
	while (src[j])
		j++;
	if (size == 0 || i == size)
		return (size + j);
	while (src[k] && l < size - i - 1)
	{
		dst[i + l] = src[k];
		l++;
		k++;
	}
	dst[i + l] = '\0';
	return (i + j);
}
