/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:49:03 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 20:49:31 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	who_is_more(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

void	sort_change1(t_list **evl, t_list **l1)
{
	t_list	*l2;
	t_list	*l3;

	l2 = (*l1)->next;
	l3 = l2->next;
	*evl = l2;
	(*l1)->next = l3;
	l2->next = (*l1);
}
