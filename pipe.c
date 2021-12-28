/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:50:15 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 20:51:13 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_com	*ft_lstgive(t_com **com, int i)
{
	t_com	*l;

	l = *com;
	while (i > 0)
	{
		l = l->next;
		i--;
	}
	return (l);
}

int	execve_for_pipe(t_com *com, char **ev, t_list **evl)
{
	if (ft_strchr(com->name, '/'))
	{
		if (!check_access_dir(com))
			exit(1);
	}
	if (ft_exec_other(com, evl) >= 0)
		exit(0);
	else
		ft_exec_sim(com, ev, evl);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(com->name, 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(1);
}

void	ft_child_b(t_com *com, char **ev, t_list **evl, int fd_out)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		if (fd_out != -1)
			dup2(fd_out, STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve_for_pipe(com, ev, evl);
	}
	else
	{
		usleep(100);
		dup2(fd[0], STDIN_FILENO);
		if (com->next->fd_in != -1)
			dup2(com->next->fd_in, STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

int	ft_exec_pipe(t_com **com, char **ev, t_list **evl)
{
	int		i;
	int		count_l;
	t_com	*l;
	int		fd_out;

	count_l = ft_lstcount(com);
	l = *com;
	if (l->fd_in != -1)
		dup2(l->fd_in, STDIN_FILENO);
	else
		dup2(0, STDIN_FILENO);
	i = 0;
	while (i < count_l - 1)
	{
		fd_out = l->fd_out;
		l = ft_lstgive(com, i++);
		ft_child_b(l, ev, evl, fd_out);
	}
	l = ft_lstgive(com, i);
	if (l->fd_out != -1)
		dup2(l->fd_out, STDOUT_FILENO);
	else
		dup2(1, STDOUT_FILENO);
	execve_for_pipe(l, ev, evl);
	return (1);
}
