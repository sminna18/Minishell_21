/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:20:09 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 19:35:30 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nlist;

	nlist = *lst;
	while (*lst)
	{
		del((*lst)->content);
		nlist = *lst;
		*lst = (*lst)->next;
		free(nlist);
	}
	*lst = 0;
}
