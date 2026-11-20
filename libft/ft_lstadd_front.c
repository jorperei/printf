/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 19:54:40 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/15 20:13:51 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	lst[0] = new;
}

/*
int	main(void)
{
	t_list	*teste;

	teste = ft_lstnew("B");
	ft_lstadd_front(&teste, ft_lstnew("A"));
	printf("%s\n", (char *)teste->content);
	printf("%s\n", (char *)teste->next->content);
	free(teste->next);
	free(teste);
	return (0);
}*/