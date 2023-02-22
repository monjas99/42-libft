/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmonjas- <dmonjas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:18:57 by david             #+#    #+#             */
/*   Updated: 2023/02/01 12:34:42 by dmonjas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clear(void *i, t_list *new_list, void (del)(void *))
{
	(del)(i);
	ft_lstclear(&new_list, del);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*aux;
	void	*i;

	i = 0;
	if (!lst || !del || !f)
		return (0);
	aux = NULL;
	new_list = aux;
	while (lst)
	{
		i = (f)(lst->content);
		if (!i)
			return (ft_clear(i, new_list, del));
		aux = ft_lstnew(i);
		if (!aux)
			return (ft_clear(i, new_list, del));
		lst = lst->next;
		ft_lstadd_back(&new_list, aux);
	}
	return (new_list);
}
