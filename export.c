/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:48:09 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:07:43 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ebannyi_tipo_unset1(char *arg, t_list **l1, t_list **l2, t_list **evl)
{
	if (!ft_strchr(arg, '='))
		return (1);
	*evl = *l2;
	free(*l1);
	return (0);
}

int	ebannyi_tipo_unset2(char *arg, t_list **l1, t_list **l3, t_list **l2)
{
	if (!ft_strchr(arg, '='))
		return (1);
	(*l1)->next = *l3;
	free(*l2);
	return (0);
}

int	tipo_unset_help(char *arg, t_list **evl)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	char	*help[100];

	l1 = *evl;
	while (l1 && l1->next)
	{
		l2 = l1->next;
		l3 = l2->next;
		help[1] = (char *)(l1->content);
		help[2] = (char *)(l2->content);
		if (tipo_unset_h_c1(arg, evl, help[1], l1) == 1)
			return (ebannyi_tipo_unset1(arg, &l1, &l2, evl));
		else if (tipo_unset_h_c2(arg, help[2]) == 1)
			return (ebannyi_tipo_unset2(arg, &l1, &l3, &l2));
		l1 = l1->next;
	}
	return (0);
}

int	tipo_unset(char *arg, t_list **evl)
{
	t_list	*l1;
	char	*help;

	l1 = *evl;
	if (l1 && !l1->next)
	{
		help = (char *)(l1->content);
		if (ft_strncmp(help, arg, ft_strlen_sym(help, '=')) == 0
			&& (arg[ft_strlen_sym(help, '=')] == '\0'
				|| arg[ft_strlen_sym(help, '=')] == '='))
		{
			if (!ft_strchr(arg, '='))
				return (1);
			*evl = NULL;
			free(l1);
		}
	}
	else
		return (tipo_unset_help(arg, evl));
	return (0);
}

int	ft_export(t_com *com, t_list **evl)
{
	int		i;

	ft_sort_easy(evl);
	if (!com->flags[1])
		export_print_sim(evl);
	else
	{
		i = 1;
		while (com->flags[i])
		{
			if (com->flags[i] && parsing_export(com->flags[i]))
			{
				if (tipo_unset(com->flags[i], evl) == 0)
					ft_lstadd_back(evl, ft_lstnew(ft_strdup(com->flags[i])));
			}
			else
				return (1);
			i++;
		}
	}
	return (0);
}
