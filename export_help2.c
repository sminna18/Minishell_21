/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_help2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:48:58 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 21:50:13 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sort_change2(t_list **ll1)
{
	t_list	*l2;
	t_list	*l3;
	t_list	*l4;
	t_list	*l1;

	l1 = *ll1;
	l2 = l1->next;
	l3 = l2->next;
	l4 = l3->next;
	l1->next = l3;
	l2->next = l4;
	l3->next = l2;
}

int	sort_count(t_list **evl)
{
	int		i;
	t_list	*l1;

	i = -2;
	l1 = *evl;
	while (l1)
	{
		l1 = l1->next;
		i++;
	}
	return (i);
}

void	print_simple_export(char *str)
{
	int	i;

	i = 0;
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	while (str[i] && str[i] != '=')
	{
		ft_putchar_fd(str[i], STDOUT_FILENO);
		i++;
	}
	if (!str[i])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return ;
	}
	ft_putchar_fd('=', STDOUT_FILENO);
	ft_putchar_fd('"', STDOUT_FILENO);
	while (str[++i] && str[i] != '=')
		ft_putchar_fd(str[i], STDOUT_FILENO);
	ft_putchar_fd('"', STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

void	export_print_sim(t_list **evl)
{
	t_list	*l1;
	char	*help;

	l1 = *evl;
	while (l1)
	{
		help = (char *)(l1->content);
		if (help[0] == '_' && help[1] == '=')
			ft_putstr_fd("", 1);
		else
			print_simple_export(help);
		l1 = l1->next;
	}
}

void	ft_sort_easy(t_list **evl)
{
	t_list	*l1;
	char	*h;
	int		mas[5];

	mas[0] = sort_count(evl);
	while (mas[0] > 0)
	{
		mas[1] = mas[0] + 1;
		mas[3] = 0;
		while (mas[1] > 0)
		{
			l1 = *evl;
			mas[2] = 0;
			while (++mas[2] < mas[3])
				l1 = l1->next;
			h = (char *)(l1->next->content);
			if (mas[3] == 0 && who_is_more((char *)(l1->content), h) > 0)
				sort_change1(evl, &l1);
			else if (who_is_more(h, (char *)(l1->next->next->content)) > 0)
				sort_change2(&l1);
			mas[3]++;
			mas[1]--;
		}
		mas[0]--;
	}
}
