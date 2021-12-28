/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:26 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 19:59:01 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	name_flags_parser(t_com *com, t_shell *shell, int i)
{
	int		start;
	int		end;

	start = 0;
	while (shell->str[i][start] && shell->str[i][start] == ' ')
		start++;
	end = start;
	while (shell->str[i][end] && shell->str[i][end] != ' ')
		end++;
	com->name = ft_substr(shell ->str[i], start, end - start);
	com->flags = ft_split(shell->str[i], ' ');
	if (ft_strchr(com->name, '/'))
		com->path = ft_substr(shell ->str[i], start, end - start);
	else
		com->path = ft_strdup("NULL");
}

void	restructuring(t_shell *shell, t_com *com)
{
	int		i;
	t_com	*com2;

	com->next = NULL;
	com->fd_in = shell->pipes[0].fd_in;
	com->fd_out = shell->pipes[0].fd_out;
	name_flags_parser(com, shell, 0);
	i = 1;
	while (i < shell->pipe_count)
	{
		com2 = malloc(sizeof (t_com));
		com->next = com2;
		com = com2;
		com->next = NULL;
		com->fd_in = shell->pipes[i].fd_in;
		com->fd_out = shell->pipes[i].fd_out;
		name_flags_parser(com, shell, i);
		i++;
	}
}

void	work_with_pipes(t_shell *shell, t_com *com, t_list **evl, char **str1)
{
	int		i;

	i = -1;
	while (++i < shell->func_count)
	{
		shell->str = ft_split_shell(str1[i], '|', -1, shell);
		shell->pipes[i].pipe_count = shell->pipe_count;
		if (!fd_redirect(shell) && !shell->error)
		{
			restructuring(shell, com);
			shell->error_cod = timur(shell->envp, com, evl);
		}
		split_fresher(shell->str, shell->pipe_count);
	}
	split_fresher(str1, shell->func_count);
}

void	main_part(t_shell *shell, t_com *com, t_list **evl)
{
	char	*str;
	char	**str1;

	shell->error = 0;
	shell->free = 0;
	str = readline("minishell> ");
	if (str == NULL)
		sign_d(shell);
	if (ft_strncmp(str, "\0", 1) != 0)
		add_history (str);
	create_flag(str, shell);
	if (!preparser(str) && !shell->error)
	{
		str = shell_parser(str, shell);
		shell->error = error_checker(str, shell);
		memor_for_pipe_flags(str, shell, -1, 0);
		str1 = ft_split_shell(str, ';', -1, shell);
		write_pipe_flags(shell);
		work_with_pipes(shell, com, evl, str1);
	}
	free(str);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_shell	*shell;
	t_com	*com;
	t_list	*evl;

	shell = malloc(sizeof (t_shell));
	com = (t_com *)malloc(sizeof(t_com));
	param_preparation(argc, argv, envp, shell);
	evl = make_ev(envp);
	while (1)
	{
		main_part(shell, com, &evl);
		i = 0;
		while (i < shell->func_count && shell->free)
		{
			free(shell->flags_for_prog[i]);
			i++;
		}
	}
}

//		 int xx;
//		 xx = 0;
//		 while (xx < shell->pipe_count)
//		 {
//		 	printf("LAST[%d][%d]=(%s)\n", i, xx, shell->str[xx]);
//		 	xx++;
//		 }