/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 20:54:21 by sminna            #+#    #+#             */
/*   Updated: 2021/10/11 13:59:30 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*rlist;

	if (!lst || !f)
		return (0);
	rlist = 0;
	while (lst)
	{
		nlist = ft_lstnew(f(lst->content));
		if (!nlist)
		{
			del(nlist);
			return (0);
		}
		else
			ft_lstadd_back(&rlist, nlist);
		lst = lst->next;
	}
	return (rlist);
}
