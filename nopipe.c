/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nopipe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:47:25 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:21:27 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*change_name(char *str)
{
	int		i;

	i = ft_strlen(str) - 1;
	while (str[i] == '/')
	{
		str[i] = '\0';
		i--;
	}
	return (str);
}

int	p_access_er(char *s1, char *s2)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s1, 2);
	ft_putstr_fd(s2, 2);
	return (0);
}

int	check_access_dir_help(t_com *com, DIR *dir, int iden)
{
	if (access(com->name, 1) == 0 && iden == 0)
	{
		if (com->name[ft_strlen(com->name) - 1] == '/')
			return (p_access_er(com->flags[0], ": Not a directory\n"));
		com->name = make_new_name(com->name);
		com->flags[0] = make_new_name(com->flags[0]);
		return (1);
	}
	else if (dir)
	{
		p_access_er(com->flags[0], ": is a directory\n");
		closedir(dir);
	}
	else
		p_access_er(com->flags[0], ": Not a directory\n");
	return (2);
}

int	check_access_dir(t_com *com)
{
	int		iden;
	int		ch;
	DIR		*dir;

	if (com->name[ft_strlen(com->name) - 1] == '/' && com->name[1] != '\0')
	{
		iden = 1;
		com->name = change_name(com->name);
		com->flags[0] = change_name(com->flags[0]);
	}
	else
		iden = 0;
	dir = opendir(com->name);
	if (dir)
		iden = 1;
	if (access(com->name, 0) == 0)
	{
		ch = check_access_dir_help(com, dir, iden);
		if (ch != 2)
			return (ch);
	}
	else
		return (p_access_er(com->flags[0], ": No such file or directory\n"));
	return (0);
}

int	ft_exec_one(t_com *com, char **ev, t_list **evl)
{
	pid_t	pid;
	int		rez;

	ft_exec_one_help(com);
	if (ft_strchr(com->name, '/'))
	{
		if (!check_access_dir(com))
			return (127);
	}
	rez = ft_exec_other(com, evl);
	if (rez >= 0)
		return (rez);
	else
	{
		pid = fork();
		if (pid == 0)
		{
			ft_exec_sim(com, ev, evl);
			p_access_er(com->name, ": command not found\n");
			exit(1);
		}
		waitpid(pid, NULL, 0);
	}
	return (127);
}
