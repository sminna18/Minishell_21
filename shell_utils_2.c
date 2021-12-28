/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:40:01 by sminna            #+#    #+#             */
/*   Updated: 2021/12/27 18:57:24 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	fd_file_exist(char *str, int j, int n)
{
	if (!str[j + n])
	{
		printf("syntax error near unexpected token newline\n");
		return (1);
	}
	return (0);
}

void	tmp_write(t_shell *shell, char c, int i)
{
		shell->tmp_split = c;
		shell->tmp_split2 = i;
}

void	record_num(int count, t_shell *shell, char c)
{
	if (c == ';')
		shell->func_count = count;
	if (c == '|')
	{
		shell->pipe_count = count;
		if (count > shell->pipe_count_max)
			shell->pipe_count_max = count;
	}
}

void	split_fresher(char **str, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		free(str[i]);
	free(str);
}

void	param_preparation(int argc, char **argv, char **envp, t_shell *shell)
{
	(void)argc;
	(void)argv;
	signal(SIGINT, sigin_c);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	shell->envp = envp;
	shell->error = 0;
	shell->longs = 4096;
	shell->flags_count = -1;
	shell->cycle = 0;
	shell->error_cod = 0;
}
