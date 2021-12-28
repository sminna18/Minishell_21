/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 21:39:51 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:23:15 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_help(char *help)
{
	if (help[0] == '_' && help[1] == '=')
	{
		ft_putstr_fd("_=/usr/bin/env", STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		ft_putstr_fd(help, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
}

void	ft_exec_one_help(t_com *com)
{
	if (com->fd_in != -1)
		dup2(com->fd_in, STDIN_FILENO);
	if (com->fd_out != -1)
		dup2(com->fd_out, STDOUT_FILENO);
}
