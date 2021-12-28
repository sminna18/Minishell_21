/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 14:03:01 by sminna            #+#    #+#             */
/*   Updated: 2021/12/26 15:31:13 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigin_c(int val)
{
	(void)val;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	sign_d(t_shell	*shell)
{
	(void)shell;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("exit \n", 1);
	exit(0);
}

int	error_checker(char *str, t_shell *shell)
{
	int	i;
	int	e;

	i = 0;
	e = 1;
	while (str[i])
	{
		if ((str[i] == ';' || str[i] == '|') && shell->flags[i])
		{
			if (e == 1)
			{
				printf("syntax error near unexpected token `%c'\n", str[i]);
				return (1);
			}
			e = 1;
		}
		else if (str[i] != ' ')
			e = 0;
		i++;
	}
	return (0);
}

void	create_flag(char *str, t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->flags_count != -1)
		free(shell->flags);
	while (str[i])
		i++;
	shell->flags_count = i;
	shell->flags = malloc(sizeof(int) * i + shell->longs);
	i = 0;
	while (i < shell->flags_count)
	{
		shell->flags[i] = 0;
		i++;
	}
}

t_list	*make_ev(char **ev)
{
	t_list	*evl;
	int		i;

	i = 0;
	evl = NULL;
	while (ev[i])
	{
		ft_lstadd_front(&evl, ft_lstnew(ft_strdup(ev[i])));
		i++;
	}
	return (evl);
}
