/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:47:40 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:12:46 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_cd_pwd_help(t_list **evl, char *oldpwd)
{
	t_list	*l1;
	char	*help1;

	l1 = *evl;
	while (l1)
	{
		if (!ft_strncmp((char *)(l1->content), "OLDPWD", 6)
			&& (((char *)(l1->content))[6] == '\0'
				|| ((char *)(l1->content))[6] == '='))
		{
			help1 = ft_strjoin("OLDPWD=", oldpwd);
			l1->content = (void *)help1;
		}
		l1 = l1->next;
	}
}

int	make_cd_pwd(t_list **evl, char *oldpwd)
{
	t_list	*l1;
	char	*help;
	char	str[500];

	l1 = *evl;
	while (l1)
	{
		if (!ft_strncmp((char *)(l1->content), "PWD", 3)
			&& (((char *)(l1->content))[3] == '\0'
				|| ((char *)(l1->content))[3] == '='))
		{
			getcwd(str, 200);
			help = ft_strjoin("PWD=", str);
			l1->content = (void *)help;
		}
		l1 = l1->next;
	}
	make_cd_pwd_help(evl, oldpwd);
	return (0);
}

void	ft_cd_help(t_com *com, char *oldpwd, t_list **evl)
{
	char	*path;
	char	*path_h;

	path = malloc(500);
	getcwd(path, 500);
	path_h = ft_strjoin(path, "/");
	free(path);
	path = ft_strjoin(path_h, com->flags[1]);
	free(path_h);
	if (chdir(path) == -1)
	{
		free(path);
		path = ft_strjoin("minishell: cd: ", com->flags[1]);
		perror(path);
	}
	else
		make_cd_pwd(evl, oldpwd);
	free(path);
}

int	ft_cd(t_com *com, t_list **evl)
{
	char	*path;
	char	oldpwd[500];

	getcwd(oldpwd, 500);
	if (!com->flags[1])
		return (0);
	if (com->flags[1][0] == '/')
	{
		if (chdir(com->flags[1]) == -1)
		{
			path = ft_strjoin("minishell: cd: ", com->flags[1]);
			perror(path);
			free(path);
			return (1);
		}
		else
			make_cd_pwd(evl, oldpwd);
	}
	else
		ft_cd_help(com, oldpwd, evl);
	return (0);
}

int	ft_env(t_com *com, t_list **evl)
{
	t_list	*l;
	char	*help;

	l = *evl;
	if (com->flags[1] == NULL)
	{
		while (l)
		{
			if (ft_strchr((char *)(l->content), '='))
			{
				help = (char *)(l->content);
				env_help(help);
			}
			l = l->next;
		}
	}
	else
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(com->flags[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
	return (0);
}
