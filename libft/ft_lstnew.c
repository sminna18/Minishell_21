/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:02:12 by sminna            #+#    #+#             */
/*   Updated: 2021/10/10 18:02:50 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist == 0)
		return (0);
	nlist->content = content;
	nlist->next = 0;
	return (nlist);
}
