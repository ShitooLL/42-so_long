/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laliao <laliao@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 23:27:07 by laliao            #+#    #+#             */
/*   Updated: 2021/12/23 01:38:01 by laliao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*destlist;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	destlist = ft_lstnew((*f)(lst->content));
	if (!destlist)
		return (NULL);
	tmp = destlist;
	while (lst)
	{
		lst = lst->next;
		if (lst)
		{
			tmp->next = ft_lstnew((*f)(lst->content));
			if (!(tmp->next))
			{
				ft_lstclear(&destlist, del);
				return (NULL);
			}
			tmp = tmp->next;
		}
	}
	return (destlist);
}
