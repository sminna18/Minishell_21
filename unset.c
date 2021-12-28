/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:50:43 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 20:51:13 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_help2(t_com *com, int i, t_list **evl, t_list **l1)
{
	char	*help1;

	help1 = (char *)((*l1)->content);
	if (ft_strncmp(help1, com->flags[i], ft_strlen_sym(help1, '=')) == 0
		&& (com->flags[i][ft_strlen_sym(help1, '=')] == '\0'
		|| com->flags[i][ft_strlen_sym(help1, '=')] == '='))
	{
		*evl = NULL;
		free(*l1);
	}
}

int	unset_help31(t_com *com, int i, char *help)
{
	if (ft_strncmp(help, com->flags[i], ft_strlen_sym(help, '=')) == 0
		&& (com->flags[i][ft_strlen_sym(help, '=')] == '\0'
		|| com->flags[i][ft_strlen_sym(help, '=')] == '='))
	{
		return (1);
	}
	return (0);
}

int	unset_help32(char *hel2, t_com *com, int i)
{
	if (ft_strncmp(hel2, com->flags[i], ft_strlen_sym(hel2, '=')) == 0
		&& (com->flags[i][ft_strlen_sym(hel2, '=')] == '\0'
		|| com->flags[i][ft_strlen_sym(hel2, '=')] == '='))
	{
		return (1);
	}
	return (0);
}

void	unset_help3(t_com *com, int i, t_list **evl)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;
	char	*help;

	l1 = *evl;
	while (l1 && l1->next)
	{
		l2 = l1->next;
		l3 = l2->next;
		help = (char *)(l1->content);
		if (l1 == *evl && unset_help31(com, i, help) == 1)
		{
			*evl = l2;
			free(l1);
			return ;
		}
		else if (unset_help32((char *)(l2->content), com, i) == 1)
		{
			l1->next = l3;
			free(l2);
			return ;
		}
		l1 = l1->next;
	}
}

int	ft_unset(t_com *com, t_list **evl)
{
	t_list	*l1;
	int		i;

	i = 1;
	while (com->flags[i])
	{
		l1 = *evl;
		if (!check_arg_unset(com->flags[i]))
			return (unset_help1(com, i));
		else if (l1 && !l1->next)
			unset_help2(com, i, evl, &l1);
		else
			unset_help3(com, i, evl);
		i++;
	}
	return (0);
}
