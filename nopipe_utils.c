/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nopipe_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:49:59 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/26 21:41:24 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_sim_help(t_com *com, char **ev, t_list *l)
{
	char	**paths;
	char	*path;
	int		j;

	j = 0;
	while (l)
	{
		if (ft_strnstr((char *)(l->content), "PATH", 4)
			&& ((char *)(l->content))[4] == '=')
			break ;
		l = l->next;
	}
	if (!l)
		return (2);
	paths = ft_split(((char *)(l->content)) + 5, ':');
	while (paths[j])
	{
		path = ft_strjoin(paths[j], "/");
		path = ft_strjoin(path, com->flags[0]);
		execve(path, com->flags, ev);
		free(path);
		j++;
	}
	return (1);
}

void	ft_exec_sim(t_com *com, char **ev, t_list **evl)
{
	char	*path;
	t_list	*l;
	char	pwd[500];

	if (!ft_strncmp("NULL", com->path, 500000))
	{
		l = *evl;
		if (ft_exec_sim_help(com, ev, l) == 2)
			return ;
	}
	else
	{
		if (com->path[0] == '.' && com->path[1] == '/')
		{
			getcwd(pwd, 500);
			path = ft_strjoin(pwd, com->path + 1);
			execve(path, com->flags, ev);
		}
		else
			execve(com->path, com->flags, ev);
	}
}

int	ft_exec_other(t_com *com, t_list **evl)
{
	if (!ft_strncmp(com->name, "pwd", 5000000))
		return (ft_pwd());
	else if (!ft_strncmp(com->name, "echo", 5000000))
		return (ft_echo(com));
	else if (!ft_strncmp(com->name, "cd", 5000000))
		return (ft_cd(com, evl));
	else if (!ft_strncmp(com->name, "export", 5000000))
		return (ft_export(com, evl));
	else if (!ft_strncmp(com->name, "unset", 5000000))
		return (ft_unset(com, evl));
	else if (!ft_strncmp(com->name, "env", 5000000))
		return (ft_env(com, evl));
	else if (!ft_strncmp(com->name, "exit", 5000000))
		return (ft_exit(com, evl));
	return (-1);
}

char	*make_new_name(char *str)
{
	int		i;
	int		c_s;
	char	*new;

	i = 0;
	c_s = 0;
	while (str[i])
	{
		if (str[i] == '/')
			c_s = i;
		i++;
	}
	new = malloc(1000);
	i = 0;
	while (str[c_s])
	{
		new[i] = str[c_s];
		i++;
		c_s++;
	}
	free(str);
	return (new);
}
