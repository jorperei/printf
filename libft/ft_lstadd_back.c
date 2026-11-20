/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:41:03 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/16 19:11:01 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	t = ft_lstlast(*lst);
	t->next = new;
}
/*
int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew("A"));
	ft_lstadd_back(&lst, ft_lstnew("B"));
	ft_lstadd_back(&lst, ft_lstnew("C"));
	printf("%s\n", (char *)lst->content);
	printf("%s\n", (char *)lst->next->content);
	printf("%s\n", (char *)lst->next->next->content);
	printf("%p\n", (void *)lst->next->next->next);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	return (0);
}*/
