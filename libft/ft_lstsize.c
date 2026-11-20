/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:53:19 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/16 17:21:28 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;
	t_list			*t;

	i = 1;
	if (!lst)
		return (0);
	t = lst;
	while (t->next != NULL)
	{
		i++;
		t = t->next;
	}
	return (i);
}
/*
int	main(void)
{
	t_list	*teste = ft_lstnew("sushi");

	ft_lstadd_front(&teste, ft_lstnew("tata"));
	ft_lstadd_front(&teste, ft_lstnew("tato"));
	printf("%d\n", ft_lstsize(teste));
	return (0);
}*/
