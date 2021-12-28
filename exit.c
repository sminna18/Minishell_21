/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:47:48 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:15:21 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clear_all_com(t_com *com)
{
	t_com	*l1;
	int		i;
	int		auf;

	auf = 0;
	while (com)
	{
		free(com->name);
		i = -1;
		while (com->flags[++i])
			free(com->flags[i]);
		free(com->flags);
		free(com->path);
		if (com->fd_in != -1)
			close(com->fd_in);
		if (com->fd_out != -1)
			close(com->fd_out);
		l1 = com;
		com = com->next;
		if (auf != 0)
			free(l1);
		auf++;
	}
	return (0);
}

void	ft_exit_error(t_com *com, t_list **evl)
{
	int	i;

	i = 0;
	while (com->flags[1][i])
	{
		if (!ft_isdigit(com->flags[1][i]))
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(com->flags[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			ft_lstclear(evl, free);
			clear_all_com(com);
			exit(1);
		}
		i++;
	}
}

int	ft_exit(t_com *com, t_list **evl)
{
	if (!com->flags[1])
	{
		ft_lstclear(evl, free);
		clear_all_com(com);
		exit(0);
	}
	else
	{
		if (com->flags[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments", 2);
			return (1);
		}
		else
		{
			ft_exit_error(com, evl);
			ft_lstclear(evl, free);
			exit(ft_atoi(com->flags[1]));
		}
	}
}
