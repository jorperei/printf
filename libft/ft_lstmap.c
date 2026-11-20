/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorperei <jorperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 14:20:17 by jorperei          #+#    #+#             */
/*   Updated: 2026/11/18 19:32:47 by jorperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *))
{
	t_list	*new;
	t_list	*t;
	void	*c;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	t = NULL;
	while (lst)
	{
		c = f(lst->content);
		t = ft_lstnew(c);
		if (!t)
		{
			del(c);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, t);
		lst = lst->next;
	}
	return (new);
}
