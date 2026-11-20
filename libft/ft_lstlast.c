/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:06:04 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/16 18:40:43 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*t;

	if (!lst)
		return (NULL);
	t = lst;
	while (t->next != NULL)
		t = t->next;
	return (t);
}
/*
int	main(void)
{
	t_list	*teste = ft_lstnew("A");
	t_list	*i;
	t_list	*last;

	ft_lstadd_front(&teste, ft_lstnew("B"));
	ft_lstadd_front(&teste, ft_lstnew("C"));
	last = ft_lstlast(teste);
	i = teste;
	printf("%s\n", (char *)last->content);
	while (teste)
	{
		i = teste->next;
		free (teste);
		teste = i;
	}
	return (0);
}*/
