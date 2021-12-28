/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:50:32 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 18:47:36 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	timur(char **ev, t_com *com, t_list **evl)
{
	pid_t	pid;
	int		rez;

	rez = 0;
	if (com && com->name[0] == '\0')
		return (clear_all_com(com));
	if (ft_lstcount(&com) == 1)
		rez = ft_exec_one(com, ev, evl);
	else if (ft_lstcount(&com) == 0)
		return (0);
	else if (ft_lstcount(&com) > 1)
	{
		pid = fork();
		if (!pid)
			ft_exec_pipe(&com, ev, evl);
		wait(0);
	}
	clear_all_com(com);
	dup2(2, STDOUT_FILENO);
	dup2(1, STDOUT_FILENO);
	dup2(1, STDIN_FILENO);
	dup2(0, STDIN_FILENO);
	return (rez);
}
