/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 16:32:39 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:01:44 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nlist;

	if (!new)
		return ;
	nlist = *lst;
	if (nlist == 0)
		*lst = new;
	else
	{
		while (nlist->next != 0)
			nlist = nlist->next;
		nlist->next = new;
	}
}
