/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdakota <kdakota@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:47:34 by kdakota           #+#    #+#             */
/*   Updated: 2021/12/27 19:51:35 by kdakota          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_sym(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

int	ft_lstcount(t_com **com)
{
	t_com	*l;
	int		i;

	l = *com;
	i = 0;
	while (l)
	{
		i++;
		l = l->next;
	}
	return (i);
}

int	ft_pwd(void)
{
	char	dir[500];

	getcwd(dir, 500);
	ft_putstr_fd(dir, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}

void	ft_echo_help(t_com *com)
{
	int	i;

	i = 3;
	ft_putstr_fd(com->flags[2], STDOUT_FILENO);
	while (com->flags[i] != NULL)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putstr_fd(com->flags[i], STDOUT_FILENO);
		i++;
	}
}

int	ft_echo(t_com *com)
{
	int	i;

	if (!com->flags[1])
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		return (0);
	}
	if (ft_strnstr(com->flags[1], "-n", ft_strlen(com->name)))
	{
		if (!com->flags[2])
			return (0);
		ft_echo_help(com);
	}
	else
	{
		i = 1;
		ft_putstr_fd(com->flags[1], STDOUT_FILENO);
		while (com->flags[++i] != NULL)
		{
			ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putstr_fd(com->flags[i], STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (0);
}
