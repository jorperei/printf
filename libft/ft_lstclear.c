/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:43:03 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:32:16 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*t;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		t = lst[0]->next;
		ft_lstdelone(*lst, del);
		*lst = t;
	}
	*lst = NULL;
}

/*
int	main(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("A")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("B")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("C")));
	printf("%s\n", (char *)lst->content);
	ft_lstclear(&lst, free);
	printf("%p\n", (void *)lst);
	ft_lstclear(&lst, free);
	return (0);
}*/